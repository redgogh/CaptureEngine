/* -------------------------------------------------------------------------------- *\
|*                                                                                  *|
|*    Copyright (C) 2019-2024 RedGogh All rights reserved.                          *|
|*                                                                                  *|
|*    Licensed under the Apache License, Version 2.0 (the "License");               *|
|*    you may not use this file except in compliance with the License.              *|
|*    You may obtain a copy of the License at                                       *|
|*                                                                                  *|
|*        http://www.apache.org/licenses/LICENSE-2.0                                *|
|*                                                                                  *|
|*    Unless required by applicable law or agreed to in writing, software           *|
|*    distributed under the License is distributed on an "AS IS" BASIS,             *|
|*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.      *|
|*    See the License for the specific language governing permissions and           *|
|*    limitations under the License.                                                *|
|*                                                                                  *|
\* -------------------------------------------------------------------------------- */
#include "main.h"

typedef std::filesystem::path Path;

void traverse_directory(const Path &dir_path, std::vector<Path> *p_dirs)
{
        if (!std::filesystem::exists(dir_path) || !std::filesystem::is_directory(dir_path))
                return;

        for (const auto &entry : std::filesystem::directory_iterator(dir_path)) {
                if (std::filesystem::is_directory(entry))
                        traverse_directory(entry.path(), p_dirs);
                p_dirs->push_back(entry.path());
        }
}

int main(int argc, char **argv)
{
        std::vector<Path> dirs;
        traverse_directory("D:\\.redgogh", &dirs);

        for (const auto &item: dirs) {
                std::cout << item.string() << std::endl;
        }

        std::cout << "file count: " << std::size(dirs) << std::endl;

        return 0;
}