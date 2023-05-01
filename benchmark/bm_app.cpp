#include <benchmark/benchmark.h>
static void BM_StringCreator(benchmark::State& state)
{
  for(auto _: state)
  {
    std::string empty_str;
  }
}
BENCHMARK(BM_StringCreator);
