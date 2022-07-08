/*
 * Copyright (c) 2022, Matthew Costa <ucosty@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "WindowManager.h"
#include "BrowserWindow.h"

WindowManager::WindowManager(Core::EventLoop& event_loop)
    : m_event_loop(event_loop)
{
}

void WindowManager::new_window(String const& url)
{
    auto window = make<BrowserWindow>(*this);
    window->setWindowTitle("Ladybird");
    window->resize(800, 600);
    window->show();

    if (!url.is_empty()) {
        window->view().load(url);
    }

    m_windows.append(move(window));
}

void WindowManager::window_closed(QMainWindow* window)
{
    m_windows.remove_first_matching([&](auto& entry) {
        return entry == window;
    });
    if (m_windows.is_empty()) {
        m_event_loop.quit(0);
    }
}
