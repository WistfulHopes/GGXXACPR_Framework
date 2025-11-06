#pragma once
#include <mutex>

#include "safetyhook.hpp"

struct PushColli
{
    int16_t stand_width{};
    int16_t stand_height{};
    int16_t sit_width{};
    int16_t sit_height{};
    int16_t sky_width{};
    int16_t sky_height{};
    int16_t sky_base_height{};
};

class GGFramework
{
private:
    GGFramework()
    {
        initialize();
    }

    static GGFramework* instance_;
    static std::mutex mtx_;

    SafetyHookMid player_main_hook_{};
    SafetyHookMid load_obj_file_hook_{};
    SafetyHookMid load_obj_file_hook_2_{};
    SafetyHookMid load_obj_file_hook_3_{};
    SafetyHookMid load_obj_file_hook_4_{};
    SafetyHookMid load_obj_file_hook_5_{};
    SafetyHookMid allocate_file_hook_{};
    SafetyHookMid allocate_file_hook_2_{};
    SafetyHookMid chara_select_hook_{};
    SafetyHookMid chara_select_hook_2_{};
    SafetyHookMid chara_select_hook_3_{};
    SafetyHookMid set_game_version_hook_{};
    SafetyHookMid load_dlc_hook_{};
    SafetyHookMid obj_file_link_hook_{};
    SafetyHookMid input_check_hook_{};
    SafetyHookMid taunt_check_hook_{};
    SafetyHookMid respect_check_hook_{};
    SafetyHookMid special_attack_check_hook_{};
    SafetyHookMid player_action_break_hook_{};
    SafetyHookMid char_pos_collision_execute_hook_{};
    SafetyHookMid char_pos_collision_execute_hook_2_{};
    SafetyHookMid char_pos_collision_execute_hook_3_{};
    SafetyHookMid char_pos_collision_execute_hook_4_{};
    SafetyHookMid char_pos_collision_execute_hook_5_{};
    SafetyHookMid char_pos_collision_execute_hook_6_{};
    SafetyHookMid char_pos_collision_execute_hook_7_{};
    SafetyHookMid char_pos_collision_execute_hook_8_{};
    SafetyHookMid char_pos_collision_execute_hook_9_{};
    SafetyHookMid char_pos_collision_execute_hook_10_{};
    SafetyHookMid char_pos_collision_execute_hook_11_{};
    SafetyHookMid char_pos_collision_execute_hook_12_{};
    SafetyHookMid char_pos_collision_execute_hook_13_{};
    SafetyHookMid char_pos_collision_execute_hook_14_{};
    SafetyHookMid normal_attack_disable_table_hook_{};
    SafetyHookMid normal_attack_disable_table_hook_2_{};
    SafetyHookMid cmn_attack_check_hook_{};
    SafetyHookMid player_throw_flag_set_hook_{};
    SafetyHookMid player_throw_flag_set_hook_2_{};
    SafetyHookMid throw_range_check_hook_{};
    SafetyHookMid throw_range_check_hook_2_{};
    SafetyHookMid air_throw_range_check_hook_x_{};
    SafetyHookMid air_throw_range_check_hook_x_2_{};
    SafetyHookMid air_throw_range_check_hook_y_{};
    SafetyHookMid air_throw_range_check_hook_y_bottom_{};
    SafetyHookMid player_throw_check_hook_{};
    SafetyHookMid player_throw_check_hook_2_{};
    SafetyHookMid player_throw_check_hook_3_{};
    SafetyHookMid player_throw_check_hook_4_{};

    static std::vector<void*> act_tbs;
    static std::vector<void*> obj_ids;
    static std::vector<std::string> chara_paths_;
    static std::vector<int32_t(*)(struct CHARACTER_WORK*)> input_check_funcs_;
    static std::vector<int32_t(*)(CHARACTER_WORK*)> taunt_check_funcs_;
    static std::vector<int32_t(*)(CHARACTER_WORK*)> respect_check_funcs_;
    static std::vector<int32_t(*)(CHARACTER_WORK*)> special_attack_check_funcs_;
    static std::vector<PushColli> push_collis_;
    static std::vector<uint32_t> normal_attack_disables_;
    static std::vector<int16_t> near_slash_dists_;
    static std::vector<int16_t> throw_ranges_;
    static std::vector<int16_t> air_throw_ranges_x_;
    static std::vector<int16_t> air_throw_ranges_y_;
    static std::vector<int16_t> air_throw_ranges_y_bottom_;
    static std::vector<uint16_t> throw_act_nos_;
    static std::vector<std::vector<uint16_t>> throw_damage_no_tbs;
    static std::vector<uint16_t> air_throw_act_nos_;
    static std::vector<std::vector<uint16_t>> air_throw_damage_no_tbs;
    static int* game_version_;
    auto initialize() -> void;

public:
    GGFramework(const GGFramework&) = delete;

    static auto GGFRAMEWORK_API get_instance() -> GGFramework*;
    
    static auto GGFRAMEWORK_API register_act_tb(void* act_tb) -> void;
    static auto GGFRAMEWORK_API register_obj_id(void* obj_id) -> void;
    static auto GGFRAMEWORK_API register_chara_id(const std::string& id) -> void;
    static auto GGFRAMEWORK_API register_input_check_func(int32_t (*func)(CHARACTER_WORK*)) -> void;
    static auto GGFRAMEWORK_API register_taunt_check_func(int32_t (*func)(CHARACTER_WORK*)) -> void;
    static auto GGFRAMEWORK_API register_respect_check_func(int32_t (*func)(CHARACTER_WORK*)) -> void;
    static auto GGFRAMEWORK_API register_special_attack_check_func(int32_t (*func)(CHARACTER_WORK*)) -> void;
    static auto GGFRAMEWORK_API register_push_colli(const PushColli& push_colli) -> void;
    static auto GGFRAMEWORK_API register_normal_attack_disable(uint32_t disable) -> void;
    static auto GGFRAMEWORK_API register_near_slash_dist(int16_t dist) -> void;
    static auto GGFRAMEWORK_API register_throw_range(int16_t range) -> void;
    static auto GGFRAMEWORK_API register_air_throw_range_x(int16_t range) -> void;
    static auto GGFRAMEWORK_API register_air_throw_range_y(int16_t range) -> void;
    static auto GGFRAMEWORK_API register_air_throw_range_y_bottom(int16_t range) -> void;
    static auto GGFRAMEWORK_API register_throw_act_no(uint16_t no) -> void;
    static auto GGFRAMEWORK_API register_throw_damage_no_tb(std::vector<uint16_t> tb) -> void;
    static auto GGFRAMEWORK_API register_air_throw_act_no(uint16_t no) -> void;
    static auto GGFRAMEWORK_API register_air_throw_damage_no_tb(std::vector<uint16_t> tb) -> void;
};
