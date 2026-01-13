#include <glaze/glaze.hpp>
#include <iostream>
#include <string>

struct Stats {
  int Kills{};
  int Deaths{};
};

struct Player {
  std::string Name;
  int Age{};
  std::string Country;
  int Point{};
  std::vector<Stats> MatchStats;
};

int main() {
  Player original{"Alice", 28, "Japan", 1200, {{10, 2}, {8, 3}, {15, 1}}};

  std::string json;
  if (auto ec = glz::write_json(original, json); ec) {
    std::cerr << "write_json failed: " << glz::format_error(ec) << "\n";
    return 1;
  }

  std::cout << "Serialized JSON:\n" << json << "\n\n";

  const std::string input = R"({
    "Name": "Bob",
    "Age": 31,
    "Country": "Canada",
    "Point": 980,
    "MatchStats":[{"Kills":9,"Deaths":4}]
  })";

  Player parsed{};
  if (auto ec = glz::read_json(parsed, input); ec) {
    std::cerr << "read_json failed: " << glz::format_error(ec) << "\n";
    return 1;
  }

  std::cout << "Parsed struct:\n";
  std::cout << "Name=" << parsed.Name << ", Age=" << parsed.Age
            << ", Country=" << parsed.Country << ", Point=" << parsed.Point
            << "\n";
  for (const auto &stats : parsed.MatchStats) {
    std::cout << "  Kills=" << stats.Kills << ", Deaths=" << stats.Deaths
              << "\n";
  }

  return 0;
}
