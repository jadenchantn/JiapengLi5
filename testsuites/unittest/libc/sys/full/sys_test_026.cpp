/*
 * Copyright (c) 2013-2019 Huawei Technologies Co., Ltd. All rights reserved.
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "It_test_sys.h"
static int TestCase(void)
{
    char *name = getlogin();
    int ret = getlogin_r(name, sizeof(name)); // Abnormal Scenario Testing
    ICUNIT_ASSERT_EQUAL(ret, 6, ret);
    ret = setenv("LOGNAME", "USER1", 1);
    ICUNIT_ASSERT_EQUAL(ret, 0, ret);

    name = getlogin();
    ICUNIT_ASSERT_STRING_EQUAL(name, "USER1", name);
    ret = getlogin_r(name, strlen(name) + 1);
    ICUNIT_ASSERT_EQUAL(ret, 0, ret);
    ret = getlogin_r(name, 1);
    ICUNIT_ASSERT_EQUAL(ret, 34, ret);

    ret = unsetenv("LOGNAME");
    ICUNIT_ASSERT_EQUAL(ret, 0, ret);

    name = getlogin();
    ICUNIT_ASSERT_EQUAL(name, nullptr, name);
    return 0;
}

VOID ItTestSys026(VOID)
{
    TEST_ADD_CASE("IT_TEST_SYS_026", TestCase, TEST_POSIX, TEST_MEM, TEST_LEVEL0, TEST_FUNCTION);
}
