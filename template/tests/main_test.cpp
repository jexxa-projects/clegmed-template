#include <gtest/gtest.h>
#include <clegmed/core/flowgraph/FlowGraph.hpp>
#include <clegmed/plugins/shortcuts.hpp>
#include <string>
#include <vector>

TEST(CLegMedTemplateTestSuite, BasicPipelineFlow) {
    using namespace clegmed::shortcuts;

    std::vector<std::string> received_data;

    auto flowgraph = clegmed::core::flowgraph::FlowGraph{}
        .from(emit("TestMessage"))
        .then(passThrough())
        .consumeWith(store(received_data)); // Fängt die Daten im Test ab

    flowgraph.
    // Einfache Überprüfung (Assertion)
    ASSERT_FALSE(received_data.empty());
    EXPECT_EQ(received_data.at(0), "TestMessage");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

