//
//      win_main.c  (12/28/2025)
//      by Jaidev Bormann
//


#include "win_main.h"


enum window_error window_hire(struct window* window)
{

        if (!window)
                return WINDOW_NULL_POINTER;


        window->instance_handle = GetModuleHandle(NULL);


        window->class.cbSize            = sizeof(WNDCLASSEX);
        window->class.hInstance         = window->instance_handle;
        window->class.lpfnWndProc       = window->procedure;
        window->class.lpszClassName     = window->class_name;

        if (!RegisterClassEx(&window->class))
                return WINDOW_FAILED_CLASS_REGISTER;


        window->handle = CreateWindowEx
        (

                window->rare.style_ex, window->class_name, window->name, window->style,
                window->x, window->y, window->width, window->height,
                window->rare.parent_handle, window->rare.menu_handle, window->instance_handle, window->rare.user_data

        );

        if (!window->handle)
        {

                UnregisterClass(window->class_name, window->instance_handle);

                return WINDOW_FAILED_CREATION;

        }


        window->device_context_handle = GetDC(window->handle);

        if (!window->device_context_handle)
        {

                DestroyWindow   (window->handle);
                UnregisterClass (window->class_name, window->instance_handle);

                return WINDOW_FAILED_DC;

        }


        window->is_running = true;


        return WINDOW_HEALTHY;

}

void window_fire(struct window* window)
{

        DestroyWindow   (window->handle);
        ReleaseDC       (window->handle, window->device_context_handle);
        UnregisterClass (window->class_name, window->instance_handle);

}


void window_center(struct window* window)
{

        HMONITOR monitor                = MonitorFromWindow(window->handle, MONITOR_DEFAULTTONEAREST);
        MONITORINFO monitor_info        = { .cbSize = sizeof(MONITORINFO) };

        if (!GetMonitorInfo(monitor, &monitor_info))
                return;


        int screen_width        = monitor_info.rcMonitor.right - monitor_info.rcMonitor.left;
        int screen_height       = monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top;

        window->x = monitor_info.rcMonitor.left + (screen_width - window->width) / 2;
        window->y = monitor_info.rcMonitor.top + (screen_height - window->height) / 2;

}

LRESULT CALLBACK window_procedure(HWND handle, UINT message, WPARAM wide_parameter, LPARAM long_parameter)
{

        switch (message)
        {

                case WM_DESTROY:

                        PostQuitMessage(0);

                        return 0;

        }


        return DefWindowProc(handle, message, wide_parameter, long_parameter);

}