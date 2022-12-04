cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    visibility = ["//visibility:public"],
    deps = ["@fmt"],
)

cc_binary(
    name = "main2",
    srcs = ["main2.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//common:io",
        "@fmt",
    ],
)
