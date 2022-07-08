/*
 * Copyright (c) 2022, Matthew Costa <ucosty@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#define AK_DONT_REPLACE_STD

#include <AK/NonnullOwnPtrVector.h>
#include <LibCore/EventLoop.h>
#include <QMainWindow>

class WindowManager {
public:
    explicit WindowManager(Core::EventLoop&);

    void new_window(String const& url);

    void window_closed(QMainWindow*);

private:
    Core::EventLoop& m_event_loop;
    NonnullOwnPtrVector<QMainWindow> m_windows;
};
