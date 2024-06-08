#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

constexpr char TAB[] = "  ";

void writeln(std::ofstream &out, std::string line, size_t notab = 0)
{
  for (int i = 0; i < notab; i++)
  {
    out << TAB;
  }
  out << line << '\n';
}
std::string tolower(std::string str)
{
  for (int i = 0; i < str.size(); i++)
  {
    str[i] = std::tolower(str[i]);
  }
  return str;
}
std::string empty() { return std::string(""); }
void generate_base(std::ofstream &out, std::string name)
{
  writeln(out, empty() + "class " + name + " {");
  writeln(out, "public:");
  writeln(out, name + "() = default;", 1);
  writeln(out, name + "(const " + name + " &other) = default;", 1);
  writeln(out,
          empty() + name + " &operator=(const " + name +
              " &other);",
          1);
  writeln(out, empty() + "virtual ~" + name + "() = default;", 1);
  writeln(out,
          empty() +
              "friend ostream &operator<<(ostream &out, const " +
              name + " &" + tolower(name) + ");",
          1);
  writeln(out, "protected:");
  writeln(out, "};\n");
}

void generate_derived(std::ofstream &out, std::string name, std::string base)
{
  writeln(out, empty() + "class " + name + " : public " + base + " {");
  writeln(out, "public:");
  writeln(out, name + "() = default;", 1);
  writeln(out, name + "(const " + name + " &other) = default;", 1);
  writeln(out,
          empty() + name + " &operator=(const " + name +
              " &other);",
          1);
  writeln(out, empty() + "virtual ~" + name + "() = default;", 1);
  writeln(out,
          empty() +
              "friend ostream &operator<<(ostream &out, const " +
              name + " &" + tolower(name) + ");",
          1);
  writeln(out, "private:");
  writeln(out, "};\n");
}

void generate_run(std::string output_dir)
{
  std::ofstream out(output_dir + "/run.sh");
  writeln(out, "#!/bin/bash");
  writeln(out, "g++ -std=c++23 main.cpp -o main");
  writeln(out, "./main");
  writeln(out, "rm main");
}

int main()
{
  std::string output_dir = ".";
  generate_run(output_dir);
  std::ofstream out(output_dir + "/main.cpp");
  out << "#include <iostream>\n";
  out << "#include <vector>\n#include<unordered_map>\n#include<memory>\nusing namespace std;\n\n";
  std::string line;
  while (true)
  {
    std::cin >> std::ws;
    std::getline(std::cin, line);
    if (line == "end")
    {
      break;
    }
    std::stringstream ss(line);
    std::string base;
    ss >> base;
    generate_base(out, base);
    std::string derived;
    while (ss >> derived)
    {
      generate_derived(out, derived, base);
    }
  }
  writeln(out, "int main() {");
  writeln(out, "return 0;");
  writeln(out, "}");
  system((empty() + "chmod +x " + output_dir + "/run.sh").c_str());
}