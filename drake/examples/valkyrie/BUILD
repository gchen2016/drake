# -*- python -*-
# This file contains rules for Bazel; see drake/doc/bazel.rst.

load(
    "//tools:drake.bzl",
    "drake_cc_binary",
    "drake_cc_googletest",
    "drake_cc_library",
)
load("//tools:lint.bzl", "add_lint_tests")
load("//tools:install_data.bzl", "install_data")

package(default_visibility = ["//visibility:public"])

drake_cc_library(
    name = "valkyrie_constants",
    srcs = ["valkyrie_constants.cc"],
    hdrs = ["valkyrie_constants.h"],
    deps = [
        "//drake/common",
    ],
)

drake_cc_library(
    name = "robot_state_decoder",
    srcs = ["robot_state_decoder.cc"],
    hdrs = ["robot_state_decoder.h"],
    deps = [
        "//drake/manipulation/util:robot_state_msg_translator",
        "//drake/multibody:rigid_body_tree",
        "//drake/systems/framework:leaf_system",
        "//drake/util",
        "//drake/util:lcm_util",
        "@lcmtypes_bot2_core",
    ],
)

drake_cc_library(
    name = "actuator_effort_to_rigid_body_plant_input_converter",
    srcs = ["actuator_effort_to_rigid_body_plant_input_converter.cc"],
    hdrs = ["actuator_effort_to_rigid_body_plant_input_converter.h"],
    deps = [
        "//drake/multibody:rigid_body_tree",
        "//drake/systems/framework",
    ],
)

drake_cc_library(
    name = "robot_command_to_desired_effort_converter",
    srcs = ["robot_command_to_desired_effort_converter.cc"],
    hdrs = ["robot_command_to_desired_effort_converter.h"],
    deps = [
        "//drake/multibody:rigid_body_tree",
        "//drake/systems/framework",
        "@lcmtypes_bot2_core",
    ],
)

drake_cc_library(
    name = "valkyrie_pd_ff_controller",
    srcs = ["valkyrie_pd_ff_controller.cc"],
    hdrs = ["valkyrie_pd_ff_controller.h"],
    data = [":models"],
    deps = [
        ":robot_state_decoder",
        ":valkyrie_constants",
        "//drake/common",
        "//drake/common:find_resource",
        "//drake/lcm",
        "//drake/multibody:kinematics_cache",
        "//drake/multibody:rigid_body_tree",
        "//drake/multibody/joints",
        "//drake/multibody/parsers",
        "//drake/systems/framework:diagram",
        "//drake/systems/framework:leaf_system",
        "//drake/systems/lcm",
        "//drake/util",
        "@lcmtypes_bot2_core",
    ],
)

drake_cc_library(
    name = "robot_state_encoder",
    srcs = ["robot_state_encoder.cc"],
    hdrs = ["robot_state_encoder.h"],
    deps = [
        "//drake/manipulation/util:robot_state_msg_translator",
        "//drake/multibody/rigid_body_plant",
        "//drake/systems/robotInterfaces:side",
        "//drake/util",
        "//drake/util:lcm_util",
    ],
)

drake_cc_library(
    name = "valkyrie_simulator",
    hdrs = ["valkyrie_simulator.h"],
    deps = [
        ":actuator_effort_to_rigid_body_plant_input_converter",
        ":robot_command_to_desired_effort_converter",
        ":robot_state_encoder",
        ":valkyrie_constants",
        "//drake/common:find_resource",
        "//drake/lcm",
        "//drake/lcmtypes:contact_info_for_viz",
        "//drake/lcmtypes:contact_results_for_viz",
        "//drake/multibody:rigid_body_tree_construction",
        "//drake/multibody/parsers",
        "//drake/multibody/rigid_body_plant",
        "//drake/multibody/rigid_body_plant:contact_results_to_lcm",
        "//drake/multibody/rigid_body_plant:drake_visualizer",
        "//drake/systems/analysis",
        "//drake/systems/framework",
        "//drake/systems/lcm",
        "//drake/systems/lcm:lcmt_drake_signal_translator",
        "//drake/systems/primitives:constant_vector_source",
        "//drake/systems/primitives:pass_through",
    ],
)

drake_cc_binary(
    name = "valkyrie_simulation",
    srcs = ["valkyrie_simulation.cc"],
    data = [":models"],
    deps = [":valkyrie_simulator"],
)

# === test/ ===

drake_cc_googletest(
    name = "robot_state_encoder_decoder_test",
    data = [":models"],
    deps = [
        ":robot_state_decoder",
        ":robot_state_encoder",
        "//drake/common:eigen_matrix_compare",
        "//drake/common:find_resource",
        "//drake/math:geometric_transform",
        "//drake/multibody:rigid_body_tree_construction",
        "//drake/multibody/parsers",
        "//drake/multibody/rigid_body_plant",
        "//drake/systems/framework:diagram",
        "//drake/systems/primitives:constant_value_source",
        "//drake/systems/primitives:constant_vector_source",
        "//drake/util",
    ],
)

drake_cc_googletest(
    name = "robot_command_to_desired_effort_converter_test",
    data = [":models"],
    deps = [
        ":robot_command_to_desired_effort_converter",
        "//drake/common:eigen_matrix_compare",
        "//drake/common:find_resource",
        "//drake/multibody/parsers",
        "//drake/systems/framework:diagram",
        "//drake/systems/primitives:constant_value_source",
    ],
)

drake_cc_googletest(
    name = "valkyrie_simulation_test",
    srcs = ["test/valkyrie_simulation_test.cc"],
    data = [":models"],
    deps = [":valkyrie_simulator"],
)

drake_cc_googletest(
    name = "valkyrie_ik_test",
    data = [":models"],
    deps = [
        "//drake/common:find_resource",
        "//drake/lcm",
        "//drake/multibody:inverse_kinematics",
        "//drake/multibody:rigid_body_constraint",
        "//drake/multibody:rigid_body_tree",
        "//drake/multibody/joints",
        "//drake/multibody/parsers",
        "//drake/multibody/rigid_body_plant:drake_visualizer",
    ],
)

install_data()

add_lint_tests()
