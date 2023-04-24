# BYCD7 2022-2023 SPIN UP

#Directories

```
├── EZ-Template@2.1.2.zip
├── Makefile
├── README.md
├── bin
│   ├── _pros_ld_timestamp.o
│   ├── autons.cpp.o
│   ├── cold.package.bin
│   ├── cold.package.elf
│   ├── hot.package.bin
│   ├── hot.package.elf
│   └── main.cpp.o
├── common.mk
├── compile_commands.json
├── firmware
│   ├── EZ-Template.a
│   ├── libc.a
│   ├── libm.a
│   ├── libpros.a
│   ├── v5-common.ld
│   ├── v5-hot.ld
│   └── v5.ld
├── include
│   ├── BYCD7.hpp
│   ├── EZ-Template
│   │   ├── PID.hpp
│   │   ├── api.hpp
│   │   ├── auton.hpp
│   │   ├── auton_selector.hpp
│   │   ├── drive
│   │   │   └── drive.hpp
│   │   ├── sdcard.hpp
│   │   └── util.hpp
│   ├── api.h
│   ├── autons.hpp
│   ├── display
│   │   ├── README.md
│   │   ├── licence.txt
│   │   ├── lv_conf.h
│   │   ├── lv_conf_checker.h
│   │   ├── lv_core
│   │   │   ├── lv_core.mk
│   │   │   ├── lv_group.h
│   │   │   ├── lv_indev.h
│   │   │   ├── lv_lang.h
│   │   │   ├── lv_obj.h
│   │   │   ├── lv_refr.h
│   │   │   ├── lv_style.h
│   │   │   └── lv_vdb.h
│   │   ├── lv_draw
│   │   │   ├── lv_draw.h
│   │   │   ├── lv_draw.mk
│   │   │   ├── lv_draw_arc.h
│   │   │   ├── lv_draw_img.h
│   │   │   ├── lv_draw_label.h
│   │   │   ├── lv_draw_line.h
│   │   │   ├── lv_draw_rbasic.h
│   │   │   ├── lv_draw_rect.h
│   │   │   ├── lv_draw_triangle.h
│   │   │   └── lv_draw_vbasic.h
│   │   ├── lv_fonts
│   │   │   ├── lv_font_builtin.h
│   │   │   └── lv_fonts.mk
│   │   ├── lv_hal
│   │   │   ├── lv_hal.h
│   │   │   ├── lv_hal.mk
│   │   │   ├── lv_hal_disp.h
│   │   │   ├── lv_hal_indev.h
│   │   │   └── lv_hal_tick.h
│   │   ├── lv_misc
│   │   │   ├── lv_anim.h
│   │   │   ├── lv_area.h
│   │   │   ├── lv_circ.h
│   │   │   ├── lv_color.h
│   │   │   ├── lv_font.h
│   │   │   ├── lv_fs.h
│   │   │   ├── lv_gc.h
│   │   │   ├── lv_ll.h
│   │   │   ├── lv_log.h
│   │   │   ├── lv_math.h
│   │   │   ├── lv_mem.h
│   │   │   ├── lv_misc.mk
│   │   │   ├── lv_symbol_def.h
│   │   │   ├── lv_task.h
│   │   │   ├── lv_templ.h
│   │   │   ├── lv_txt.h
│   │   │   └── lv_ufs.h
│   │   ├── lv_objx
│   │   │   ├── lv_arc.h
│   │   │   ├── lv_bar.h
│   │   │   ├── lv_btn.h
│   │   │   ├── lv_btnm.h
│   │   │   ├── lv_calendar.h
│   │   │   ├── lv_canvas.h
│   │   │   ├── lv_cb.h
│   │   │   ├── lv_chart.h
│   │   │   ├── lv_cont.h
│   │   │   ├── lv_ddlist.h
│   │   │   ├── lv_gauge.h
│   │   │   ├── lv_img.h
│   │   │   ├── lv_imgbtn.h
│   │   │   ├── lv_kb.h
│   │   │   ├── lv_label.h
│   │   │   ├── lv_led.h
│   │   │   ├── lv_line.h
│   │   │   ├── lv_list.h
│   │   │   ├── lv_lmeter.h
│   │   │   ├── lv_mbox.h
│   │   │   ├── lv_objx.mk
│   │   │   ├── lv_objx_templ.h
│   │   │   ├── lv_page.h
│   │   │   ├── lv_preload.h
│   │   │   ├── lv_roller.h
│   │   │   ├── lv_slider.h
│   │   │   ├── lv_spinbox.h
│   │   │   ├── lv_sw.h
│   │   │   ├── lv_ta.h
│   │   │   ├── lv_table.h
│   │   │   ├── lv_tabview.h
│   │   │   ├── lv_tileview.h
│   │   │   └── lv_win.h
│   │   ├── lv_themes
│   │   │   ├── lv_theme.h
│   │   │   ├── lv_theme_alien.h
│   │   │   ├── lv_theme_default.h
│   │   │   ├── lv_theme_material.h
│   │   │   ├── lv_theme_mono.h
│   │   │   ├── lv_theme_nemo.h
│   │   │   ├── lv_theme_night.h
│   │   │   ├── lv_theme_templ.h
│   │   │   ├── lv_theme_zen.h
│   │   │   └── lv_themes.mk
│   │   ├── lv_version.h
│   │   └── lvgl.h
│   ├── main.h
│   └── pros
│       ├── adi.h
│       ├── adi.hpp
│       ├── api_legacy.h
│       ├── apix.h
│       ├── colors.h
│       ├── colors.hpp
│       ├── distance.h
│       ├── distance.hpp
│       ├── error.h
│       ├── ext_adi.h
│       ├── gps.h
│       ├── gps.hpp
│       ├── imu.h
│       ├── imu.hpp
│       ├── link.h
│       ├── link.hpp
│       ├── llemu.h
│       ├── llemu.hpp
│       ├── misc.h
│       ├── misc.hpp
│       ├── motors.h
│       ├── motors.hpp
│       ├── optical.h
│       ├── optical.hpp
│       ├── rotation.h
│       ├── rotation.hpp
│       ├── rtos.h
│       ├── rtos.hpp
│       ├── screen.h
│       ├── screen.hpp
│       ├── serial.h
│       ├── serial.hpp
│       ├── vision.h
│       └── vision.hpp
├── project.pros
└── src
    ├── autons.cpp
    └── main.cpp
```

# Explaination

`include/BYCD7.hpp`

- Define Port

`src/main.cpp`

- Drive chassis Setting
- Initialize Code
- OpControl Code

`src/autons.cpp`

- Auton Code

# How to use

## build

```
pros build
```

## Upload

```
pros upload
```
