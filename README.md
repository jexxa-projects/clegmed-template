# CLegMed Project Template

A production-ready project template for generating modern C++23 applications based 
on the [CLegMed](https://github.com/jexxa-projects/CLegMed) framework. 
It uses [Copier](https://readthedocs.io) to automate boilerplate generation, toolchain setup, 
and dependency management.

## 🚀 Features

- **Instant Setup**: Generates a fully configured out-of-source CMake build environment.
- **Dependency Automation**: Automatically integrates `CLegMed` and `GoogleTest` via CMake's `FetchContent`.
- **Regulatory Foundation**: Includes a pre-configured `REQUIREMENTS.md` template and standard-compliant Git hooks layout to match CLegMed's quality gates.
- **Modern Standards**: Pre-configured for C++23, standard warning levels, and automated test runners via CTest.

## 📋 Prerequisites

Before scaffolding a new application, ensure you have the following tools installed:

1. **Python 3.10+** (Required to run Copier)
2. **Copier**: Install it globally or via `pipx`:
   ```bash
   pipx install copier
   # Or via standard pip
   pip install copier
   ```
3. **C++23 Compliant Toolchain**: GCC 13+, Apple Clang 21+, or equivalent.
4. **CMake 3.23+**

## 🛠️ How to Generate a New Project

You can generate a new project directly from this GitHub repository without cloning it manually.

### 1. Run the Generator

Open your terminal, navigate to the parent folder where your new project directory should be created, and execute:

```bash
copier copy gh:jexxa-projects/clegmed-template my-new-clegmed-app
```

### 2. Answer the Prompts

Copier will interactively ask you a few questions to customize your application structure:
- **Project Name**: The binary target name (e.g., `my-clegmed-service`).
- **Author Name / Organization**: Used for file headers and license attribution.
- **CLegMed Version**: The specific tag or branch of CLegMed you want to pin (e.g., `v0.1.0` or `main`).

### 3. Build and Run the Generated App

Once Copier finishes generating the files, switch to your new directory and trigger the compilation layout:

```bash
# Enter the generated project directory
cd my-new-clegmed-app

# 1. Create and enter the build directory
mkdir build && cd build

# 2. Configure the project and fetch upstream dependencies
cmake ..

# 3. Compile the application and test suites
cmake --build .

# 4. Run the validation suite
ctest --output-on-failure
```

## 📁 Generated Directory Structure

The template scaffolds a clean workspace architecture mirroring regulatory requirements:

```text
my-new-clegmed-app/
├── CMakeLists.txt        # Master target architecture configuration
├── REQUIREMENTS.md       # Traceability matrix for local feature specifications
├── src/
│   └── main.cpp          # Application entry point with a basic FlowGraph example
├── tests/
│   └── main_test.cpp     # Initial validation setup using GoogleTest
└── .gitignore            # Tailored patterns for C++ and IDE build files
```

## 🤝 Contributing

If you want to adjust templates, update standard prompt definitions, or fix variables, please modify the blueprint files located in the `template/` folder and adjust schema mappings in `copier.yml`.

Pull Requests are highly welcome!
