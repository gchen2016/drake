# -*- python -*-
# This file contains rules for Bazel; see drake/doc/bazel.rst.

package(default_visibility = ["//visibility:public"])

load("//tools:lint.bzl", "add_lint_tests")

genrule(
    name = "sphinx",
    srcs = glob([
        "**/*.rst",
    ]) + [
        "conf.py",
        "images/logo_w_text.jpg",
        "images/under_construction.png",
        "images/doxygen_instructions/visual_studio_build_targets.png",
    ],
    outs = ["sphinx.zip"],
    cmd = " ".join([
        # Run sphinx-build.
        "sphinx-build -b html",  # HTML output.
        "-a -E -d $(@D)/.doctrees/",  # Don't use caching.
        "-W -N -q",  # Turn warnings into errors; else be quiet.
        "$$(dirname $(location conf.py))",  # Source dir.
        "$(@D)/.tmpout",  # Output dir.
        "&&",
        # Create zipfile.
        "( CWD=`pwd` && cd $(@D)/.tmpout && zip -q -r $$CWD/$@ ./ )",
        "&&",
        # Cleanup temporary files.
        "rm -rf $(@D)/.doctrees/ $(@D)/.tmpout",
    ]),
    # Some (currently disabled) Sphinx extentions try to reach out to the
    # network; we should fail-fast if someone tries to turn them on.
    tags = ["block-network"],
)

py_binary(
    name = "serve_sphinx",
    srcs = ["serve_sphinx.py"],
    data = [":sphinx.zip"],
)

add_lint_tests(python_lint_exclude = [":conf.py"])
