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
        bool WindowShouldClose(void);

        // Check if window has been initialized successfully
        bool IsWindowReady(void);

        // Check if window is currently fullscreen
        bool IsWindowFullscreen(void);

        // Check if window is currently hidden (only PLATFORM_DESKTOP)
        bool IsWindowHidden(void);

        // Check if window is currently minimized (only PLATFORM_DESKTOP)
        bool IsWindowMinimized(void);

        // Check if window is currently maximized (only PLATFORM_DESKTOP)
        bool IsWindowMaximized(void);

        // Check if window is currently focused (only PLATFORM_DESKTOP)
        bool IsWindowFocused(void);

        // Check if window has been resized last frame
        bool IsWindowResized(void);

        // Check if one specific window flag is enabled
        bool IsWindowState(unsigned int flag);

        // Set window configuration state using flags
        void SetWindowState(unsigned int flags);

        // Clear window configuration state flags
        void ClearWindowState(unsigned int flags);

        // Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
        void ToggleFullscreen(void);

        // Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
        void MaximizeWindow(void);

        // Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
        void MinimizeWindow(void);

        // Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
        void RestoreWindow(void);

        // Set icon for window (only PLATFORM_DESKTOP)
        void SetWindowIcon(Image image);

        // Set title for window (only PLATFORM_DESKTOP)
        void SetWindowTitle(const char *title);

        // Set window position on screen (only PLATFORM_DESKTOP)
        void SetWindowPosition(int x, int y);

        // Set monitor for the current window (fullscreen mode)
        void SetWindowMonitor(int monitor);

        // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
        void SetWindowMinSize(int width, int height);

        // Set window dimensions
        void SetWindowSize(int width, int height);

        // Get native window handle
        void *GetWindowHandle(void);

        // Get current screen width
        int GetScreenWidth(void);

        // Get current screen height
        int GetScreenHeight(void);

        // Get number of connected monitors
        int GetMonitorCount(void);

        // Get current connected monitor
        int GetCurrentMonitor(void);

        // Get specified monitor position
        Vector2 GetMonitorPosition(int monitor);

        // Get specified monitor width (max available by monitor)
        int GetMonitorWidth(int monitor);

        // Get specified monitor height (max available by monitor)
        int GetMonitorHeight(int monitor);

        // Get specified monitor physical width in millimetres
        int GetMonitorPhysicalWidth(int monitor);

        // Get specified monitor physical height in millimetres
        int GetMonitorPhysicalHeight(int monitor);

        // Get specified monitor refresh rate
        int GetMonitorRefreshRate(int monitor);

        // Get window position XY on monitor
        Vector2 GetWindowPosition(void);

        // Get window scale DPI factor
        Vector2 GetWindowScaleDPI(void);

        // Get the human-readable, UTF-8 encoded name of the primary monitor
        const char *GetMonitorName(int monitor);

        // Set clipboard text content
        void SetClipboardText(const char *text);

        // Get clipboard text content
        const char *GetClipboardText(void);
    };
}