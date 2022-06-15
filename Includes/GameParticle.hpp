/*
** EPITECH PROJECT, 2022
** GameParticle.hpp
** File description:
** GameParticle
*/

#ifndef GAMEPARTICLE_HPP_
#define GAMEPARTICLE_HPP_

#include "IEntity.hpp"

#define MAX_PARTICLES 400

namespace bomberman {
    class GameParticle {
        public:
            GameParticle(Vector2& pos) : position(pos) {}
            ~GameParticle() = default;
            void Draw() {
                DrawCircle(position.x, position.y, size, YELLOW);
            }
            void Update() {
                velocity = Vector2Add(velocity, acc);
                position = Vector2Add(position, velocity);
                if (GetRandomValue(0, 100) < 30) size -= .1f;
            }
            float size{5.0f};
        private:
            Vector2 acc{0.0f, 0.05f};
            Vector2 position;
            Vector2 velocity {
                float(GetRandomValue(-20, 20))*.1f,
                float(GetRandomValue(-50, -20))*.1f
            };
    };

    class ParticleSystem : public IEntity {
        private:
            std::vector<GameParticle> particles;
        public:
            ParticleSystem() noexcept {
                particles.reserve(MAX_PARTICLES);
            }
            ~ParticleSystem() {
                particles.clear();
            }

            void Draw() {
                for (auto particle: particles) {
                    particle.Draw();
                }
            }

            void Update() {
                size_t size = particles.size();
                for (size_t i = 0; i < size; i++) {
                    particles[i].Update();
                    if (particles[i].size <= 0) {
                        particles.erase(particles.begin() + i);
                        size--;
                    }
                }
                auto m_pos = Vector2{
                    float(GetRandomValue((GetMousePosition().x-20)*10, (GetMousePosition().x+20)*10)*.1f),
                    float(GetMousePosition().y)
                };
                particles.emplace_back(m_pos);
            }
    };

}

#endif /* !GAMEPARTICLE_HPP_ */
