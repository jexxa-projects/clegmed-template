#include "clegmed/plugins/shortcuts.hpp"

int main() {
    using namespace clegmed::shortcuts;

    auto flowgraph = FlowGraph{}
        .every(2s)
        .from(emit("Hello World"))
        .then(passThrough())
        .consumeWith(logInfo());

    auto clegmed = CLegMed(std::move(flowgraph));
    clegmed.run();
}


