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

SET(MODULE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(THIRD_PARTY_DIR "${MODULE_ROOT_DIR}/Engine/Source/ThirdParty")

IF (CMAKE_CXX_COMPILE_ID STREQUAL "MSVC")
  ADD_COMPILE_OPTIONS("/source-charset:utf-8")
  ADD_COMPILE_OPTIONS("/executing-charset:utf-8")
ENDIF ()

ADD_SUBDIRECTORY("Engine/Source/Runtime")
ADD_SUBDIRECTORY("Engine/Source/Sandbox")