#include <glog/logging.h>

class Expression {
public:
  virtual int compute() = 0;
  virtual ~Expression() = default;
};

class Constant final : public Expression {
public:
  Constant(int x) : x_(x) {}

  int compute() override { return x_; }

private:
  int x_;
};

class Add final : public Expression {
public:
  Add(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r)
      : l_(std::move(l)),
        r_(std::move(r)) {}

  int compute() override { return l_->compute() + r_->compute(); }

private:
  std::unique_ptr<Expression> l_;
  std::unique_ptr<Expression> r_;
};

int main() {
  // imagine the following is constructed by parsing "40+2"
  // and not statically like this...
  auto answer = std::make_unique<Add>(
      std::make_unique<Constant>(40),
      std::make_unique<Constant>(2));

  LOG(INFO) << "answer = " << answer->compute();

  return 0;
}