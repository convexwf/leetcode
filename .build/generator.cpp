#include <coroutine>
#include <optional>
#include <iostream>

using namespace std;
using ull = unsigned long long;

template <typename T>
class Generator {
public:
    struct promise_type
    {
        std::optional<T> current_value;

        Generator get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        std::suspend_always initial_suspend() {
            return {};
        }
        std::suspend_always final_suspend() noexcept {
            return {};
        }

        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }

        void unhandled_exception() {
            throw;
        }
        void return_void() {
        }
    };

    using handle_type = std::coroutine_handle<promise_type>;

    explicit Generator(handle_type h) : coro(h) {
    }
    Generator(Generator&& rhs) noexcept : coro(rhs.coro) {
        rhs.coro = {};
    }
    ~Generator() {
        if (coro) coro.destroy();
    }

    // 获取下一个值
    std::optional<T> next() {
        if (!coro || coro.done()) return std::nullopt;
        coro.resume();
        return coro.promise().current_value;
    }

private:
    handle_type coro;
};

Generator<int> primes() {
    int n = 2;
    while (true) {
        bool is_prime = true;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        if (is_prime) co_yield n;
        ++n;
    }
}

int main() {
    auto gen = primes();

    for (int i = 0; i < 20; ++i) {
        auto v = gen.next();
        if (!v) break;
        std::cout << *v << " ";
    }
}
