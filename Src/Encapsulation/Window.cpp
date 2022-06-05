/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Window
*/

#include "Window.hpp"

namespace bomberman {
    Window::Window(const int &width,
                   const int &height,
                   const std::string &title)
                   : width(1920), height(1080), title("Bomberman") {
        InitWindow(width, height, title.c_str());
    }

    Window::~Window() {
        CloseWindow();
    }

    inline bool shouldClose(void) {
        return WindowShouldClose();
    }
    
    inline bool isReady(void) {
        return IsWindowReady();
    }

    inline bool isFullscreen(void) {
        return IsWindowFullscreen();
    }
    
    inline bool isHidden(void) {
        return IsWindowHidden();
    }
    
    inline bool isMinimized(void) {
        return IsWindowMinimized();
    }
    
    inline bool isMaximized(void) {
        return IsWindowMaximized();
    }
    
    inline bool isFocused(void) {
        return IsWindowFocused();
    }
    
    inline bool isResized(void) {
        return IsWindowResized();
    }
    
    inline bool isState(const unsigned int &flag) {
        return IsWindowState(flag);
    }
    
    inline void setState(const unsigned int &flags) {
        return SetWindowState(flags);
    }
    
    inline void clearState(const unsigned int &flags) {
        return ClearWindowState(flags);
    }
    
    inline void toggleFullscreen(void) {
        return ToggleFullscreen();
    }
    
    inline void maximize(void) {
        return MaximizeWindow();
    }
    
    inline void minimize(void) {
        return MinimizeWindow();
    }
    
    inline void restore(void) {
        return RestoreWindow();
    }
    
    inline void setIcon(const Image &image) {
        return SetWindowIcon(image);
    }
    
    inline void setTitle(const std::string &title) {
        return SetWindowTitle(title.c_str());
    }
    
    inline void setPosition(const int &x, const int &y) {
        return SetWindowPosition(x, y);
    }
    
    inline void setMonitor(const int &monitor) {
        return SetWindowMonitor(monitor);
    }
    
    inline void setMinSize(const int &width, const int &height) {
        return SetWindowMinSize(width, height);
    }
    
    inline void setSize(const int &width, const int &height) {
        return SetWindowSize(width, height);
    }
    
    inline void *getHandle(void) {
        return GetWindowHandle();
    }
    
    inline int getScreenWidth(void) {
        return GetScreenWidth();
    }
    
    inline int getScreenHeight(void) {
        return GetScreenHeight();
    }
    
    inline int getMonitorCount(void) {
        return GetMonitorCount();
    }
    
    inline int getCurrentMonitor(void) {
        return GetCurrentMonitor();
    }
    
    inline Vector2 getMonitorPosition(const int &monitor) {
        return GetMonitorPosition(monitor);
    }
    
    inline int getMonitorWidth(const int &monitor) {
        return GetMonitorWidth(monitor);
    }
    
    inline int getMonitorHeight(const int &monitor) {
        return GetMonitorHeight(monitor);
    }
    
    inline int getMonitorPhysicalWidth(const int &monitor) {
        return GetMonitorPhysicalWidth(monitor);
    }
    
    inline int getMonitorPhysicalHeight(const int &monitor) {
        return GetMonitorPhysicalHeight(monitor);
    }
    
    inline int getMonitorRefreshRate(const int &monitor) {
        return GetMonitorRefreshRate(monitor);
    }
    
    inline Vector2 getPosition(void) {
        return GetWindowPosition();
    }
    
    inline Vector2 getScaleDPI(void) {
        return GetWindowScaleDPI();
    }
    
    inline const std::string getMonitorName(const int &monitor) {
        const std::string monitorName(GetMonitorName(monitor));
        return monitorName;
    }
    
    inline void setClipboardText(const std::string &text) {
        return SetClipboardText(text.c_str());
    }
    
    inline const char *getClipboardText(void) {
        return GetClipboardText();
    }
}
