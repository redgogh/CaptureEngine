#
# Copyright (C) 2019-2024 RedGogh All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
CMAKE_MINIMUM_REQUIRED(VERSION 3.26)
PROJECT(CaptureEngine)

SET(CMAKE_CXX_STANDARD 23)

SET(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(THIRD_PARTY_DIR "${PROJECT_ROOT_DIR}/thirdparty")

INCLUDE_DIRECTORIES(SYSTEM
  "thirdparty"
  "include"
)

INCLUDE_DIRECTORIES(
  "runtime"
)

IF (CMAKE_CXX_COMPILE_ID STREQUAL "MSVC")
  ADD_COMPILE_OPTIONS("/source-charset:utf-8")
  ADD_COMPILE_OPTIONS("/executing-charset:utf-8")
ENDIF ()

FILE(GLOB_RECURSE SOURCES
  "main/*.cpp"
  "runtime/window/*.cpp"
)

LINK_DIRECTORIES(
  "${THIRD_PARTY_DIR}/GLFW/lib-mingw-w64"
  "${THIRD_PARTY_DIR}/vulkan/bin"
)

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
  "glfw3"
  "vulkan-1"
)