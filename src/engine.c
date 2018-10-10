#include <malloc.h>
#include <stdio.h>

#include "config.h"
#include "engine.h"
#include "game.h"
#include "input.h"
#include "renderer.h"
#include "ui.h"

#include "CMemleak.h"

int engine_run(void)
{
    struct engine engine;

    engine.state = ENGINE_STATE_MENU;

    config_load();

    TCOD_sys_set_fps(FPS);

    TCOD_console_set_custom_font(font_file, font_flags, font_char_horiz, font_char_vertic);
    TCOD_console_init_root(console_width, console_height, WINDOW_TITLE, fullscreen, console_renderer);

    struct input *input = input_create();
    struct game *game = game_create();
    struct ui *ui = ui_create();
    struct renderer *renderer = renderer_create();

    while (!TCOD_console_is_window_closed())
    {
        char title[256];
        sprintf(title, "%s - FPS: %d", WINDOW_TITLE, TCOD_sys_get_fps());
        TCOD_console_set_window_title(title);

        input_handle(input, &engine, game, ui);
        game_update(game, &engine);
        ui_update(ui, &engine, game);
        renderer_draw(renderer, &engine, game, ui);

        if (game->should_restart)
        {
            game_destroy(game);
            game = game_create();
        }

        if (ui->should_restart)
        {
            ui_destroy(ui);
            ui = ui_create();
        }

        if (engine.should_quit)
        {
            break;
        }
    }

    renderer_destroy(renderer);
    ui_destroy(ui);
    game_destroy(game);
    input_destroy(input);

    config_save();

    return 0;
}
