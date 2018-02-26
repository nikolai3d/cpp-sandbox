#if 0
#include <cstddef>
#include <tuple>
#include <type_traits>

template <std::size_t N>
class agf_vector {
  float _array[N];

 public:
  agf_vector() = default;

  agf_vector(float a) : _array{a} {
    static_assert(N == 1, "");
  }
  agf_vector(float a, float b) : _array{a, b} {
    static_assert(N == 2, "");
  }
  agf_vector(float a, float b, float c) : _array{a, b, c} {
    static_assert(N == 3, "");
  }
  agf_vector(float a, float b, float c, float d) : _array{a, b, c, d} {
    static_assert(N == 4, "");
  }
};

int main() {
  agf_vector<4> test(0.4f, 0.5f, 0.3f, 0.9f);
  return 0;
}

#endif


#include <benchmark/benchmark.h>

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();
