#include <string>
#include <string_view>
#include <iostream>
#include <vector>

struct Node;

enum class Kind {
    PRINT,
    SCAN,
    CONCAT,
    FILTER,
    BUFFER,
};

class Node {
public:
    Node() = default;
    virtual Kind kind() = 0;
};

class Print : public Node {
public:
    Kind kind() override {
        return Kind::PRINT;
    }
};

class Scan : public Node {
public:
    Kind kind() override {
        return Kind::SCAN;
    }
    Node* next;
};
class Concat : public Node {
public:
    Concat(std::string s) : s_(std::move(s)) {}
    Kind kind() override {
        return Kind::CONCAT;
    }
    Node* next;
    std::string s_{};
};

class Filter : public Node {
public:
    Filter(std::string s) : s_(std::move(s)) {}
    Kind kind() override {
        return Kind::FILTER;
    }
    Node* next;
    std::string s_{};
};

class Buffer : public Node {
public:
    Kind kind() override {
        return Kind::BUFFER;
    }
    Node* left;
    Node* right;
};

class InputEdge {
public:
    InputEdge(std::vector<std::string> strings) : strings_(std::move(strings)), it_(strings_.begin()) {}
    virtual bool take(std::string_view& s) {
        if(it_ != strings_.end()) {
            s = *it_++;
            return true;
        }
        return false;
    }
private:
    std::vector<std::string> strings_{};
    std::vector<std::string>::iterator it_{};
};

class OutputEdge {
public:
    virtual void offer(std::string_view s) {
        strings_.emplace_back(s);
    }
    void print() {
        for(auto s : strings_) {
            std::cout << s << std::endl;
        }
    }
private:
    std::vector<std::string> strings_{};
};

class Visitor {
public:
    Visitor(InputEdge* in, OutputEdge* out) : in_(in), out_(out) {}
    void operator()(Scan* node, std::string_view s) {
        std::string_view buf{};
        while(in_->take(buf)) {
            dispatch(node->next, buf);
        }
    }
    void operator()(Concat* node, std::string_view s) {
        std::string x{s};
        x.append(node->s_);
        dispatch(node->next, x);
    }
    void operator()(Filter* node, std::string_view s) {
        if(s.find(node->s_) != std::string_view::npos) {
            dispatch(node->next, s);
        }
    }
    void operator()(Print* node, std::string_view s) {
        out_->offer(s);
    }
    void operator()(Buffer* node, std::string_view s) {
        std::string l{s};
        std::string r{s};
        dispatch(node->left, l);
        dispatch(node->right, r);
    }
    void dispatch(Node* node, std::string_view s) {
        switch(node->kind()) {
            case Kind::SCAN:
                operator()(static_cast<Scan*>(node), s);
                return;
            case Kind::CONCAT:
                operator()(static_cast<Concat*>(node), s);
                return;
            case Kind::PRINT:
                operator()(static_cast<Print*>(node), s);
                return;
            case Kind::FILTER:
                operator()(static_cast<Filter*>(node), s);
                return;
            case Kind::BUFFER:
                operator()(static_cast<Buffer*>(node), s);
                return;
        }
        std::abort();
    }

private:
    InputEdge* in_{};
    OutputEdge* out_{};
};

class ContextualVisitor {
public:
    void operator()(Scan* node) {
        std::cout << "Scan " << std::endl;
        std::cin >> s_;
        dispatch(node->next);
    }
    void operator()(Concat* node) {
        s_.append(node->s_);
        dispatch(node->next);
    }
    void operator()(Filter* node) {
        if(s_.find(node->s_) != std::string_view::npos) {
            dispatch(node->next);
        }
    }
    void operator()(Print* node) {
        std::cout << s_ << std::endl;
    }
    void operator()(Buffer* node) {
        ContextualVisitor v1;
        ContextualVisitor v2;
        v1.s_ = s_;
        v2.s_ = s_;
        v1.dispatch(node->left);
        v2.dispatch(node->right);
    }
    void dispatch(Node* node) {
        switch(node->kind()) {
            case Kind::SCAN:
                operator()(static_cast<Scan*>(node));
                return;
            case Kind::CONCAT:
                operator()(static_cast<Concat*>(node));
                return;
            case Kind::PRINT:
                operator()(static_cast<Print*>(node));
                return;
            case Kind::FILTER:
                operator()(static_cast<Filter*>(node));
                return;
            case Kind::BUFFER:
                operator()(static_cast<Buffer*>(node));
                return;
        }
        std::abort();
    }

private:
    std::string s_{};
};

int main() {
    Scan s{};
    Buffer b{};
    Concat c{"+"};
    Filter f{"?"};
    Print p1{};
    Print p2{};
    s.next = &b;
    {
        b.left = &c;
        c.next = &p1;
    }
    {
        b.right = &f;
        f.next = &p2;
    }
    InputEdge in{{"a1", "a2", "a?"}};
    OutputEdge out{};

    Visitor v{&in, &out};
    v.dispatch(&s, "");
    std::cout << "result : ";
    out.print();
}

