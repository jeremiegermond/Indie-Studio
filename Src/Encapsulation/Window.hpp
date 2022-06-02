/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Window
*/

#pragma once

#include <iostream>
#include "raylib.h"

namespace bomberman {
    class Window {
    private:
        int width;
        int height;
        const std::string title;

    public:
        // Initialize window and OpenGL context
        Window(const int &width, const int &height, const std::string &title);

        // Close window and unload OpenGL context
        ~Window();

        // Check if KEY_ESCAPE pressed or Close icon pressed
        inline bool shouldClose(void);

        // Check if window has been initialized successfully
        inline bool isReady(void);

        // Check if window is currently fullscreen
        inline bool isFullscreen(void);

        // Check if window is currently hidden (only PLATFORM_DESKTOP)
        inline bool isHidden(void);

        // Check if window is currently minimized (only PLATFORM_DESKTOP)
        inline bool isMinimized(void);

        // Check if window is currently maximized (only PLATFORM_DESKTOP)
        inline bool isMaximized(void);

        // Check if window is currently focused (only PLATFORM_DESKTOP)
        inline bool isFocused(void);

        // Check if window has been resized last frame
        inline bool isResized(void);

        // Check if one specific window flag is enabled
        inline bool isState(const unsigned int &flag);

        // Set window configuration state using flags
        inline void setState(const unsigned int &flags);

        // Clear window configuration state flags
        inline void clearState(const unsigned int &flags);

        // Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
        inline void toggleFullscreen(void);

        // Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
        inline void maximize(void);

        // Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
        inline void minimize(void);

        // Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
        inline void restore(void);

        // Set icon for window (only PLATFORM_DESKTOP)
        inline void setIcon(const Image &image);

        // Set title for window (only PLATFORM_DESKTOP)
        inline void setTitle(const std::string &title);

        // Set window position on screen (only PLATFORM_DESKTOP)
        inline void setPosition(const int &x, const int &y);

        // Set monitor for the current window (fullscreen mode)
        inline void setMonitor(const int &monitor);

        // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
        inline void setMinSize(const int &width, const int &height);

        // Set window dimensions
        inline void setSize(const int &width, const int &height);

        // Get native window handle
        inline void *getHandle(void);

        // Get current screen width
        inline int getScreenWidth(void);

        // Get current screen height
        inline int getScreenHeight(void);

        // Get number of connected monitors
        inline int getMonitorCount(void);

        // Get current connected monitor
        inline int getCurrentMonitor(void);

        // Get specified monitor position
        inline Vector2 getMonitorPosition(const int &monitor);

        // Get specified monitor width (max available by monitor)
        inline int getMonitorWidth(const int &monitor);

        // Get specified monitor height (max available by monitor)
        inline int getMonitorHeight(const int &monitor);

        // Get specified monitor physical width in millimetres
        inline int getMonitorPhysicalWidth(const int &monitor);

        // Get specified monitor physical height in millimetres
        inline int getMonitorPhysicalHeight(const int &monitor);

        // Get specified monitor refresh rate
        inline int getMonitorRefreshRate(const int &monitor);

        // Get window position XY on monitor
        inline Vector2 getPosition(void);

        // Get window scale DPI factor
        inline Vector2 getScaleDPI(void);

        // Get the human-readable, UTF-8 encoded name of the primary monitor
        inline const std::string getMonitorName(const int &monitor);

        // Set clipboard text content
        inline void setClipboardText(const std::string &text);

        // Get clipboard text content
        inline const char *getClipboardText(void);
    };
}