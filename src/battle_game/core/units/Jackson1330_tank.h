#pragma once
#include "battle_game/core/unit.h"

namespace battle_game::unit {
class Jackson1330_Tank : public Unit {
 public:
  Jackson1330_Tank(GameCore *game_core, uint32_t id, uint32_t player_id);
  void Render() override;
  void Update() override;
  [[nodiscard]] bool IsHit(glm::vec2 position) const override;
  void Dizzying(glm::vec2 bullet_velocity) override; // newly added

 protected:
  void TankMove(float move_speed, float rotate_angular_speed);
  void TurretRotate();
  void Fire();
  [[nodiscard]] const char *UnitName() const override;
  [[nodiscard]] const char *Author() const override;

  float turret_rotation_{0.0f};
  uint32_t fire_count_down_{0};
  uint32_t mine_count_down_{0};
  uint32_t dizzying_count_down_{0}; // newly added
  glm::vec2 hitting_bullet_velocity_{0.0f}; // newly added
};
}  // namespace battle_game::unit
