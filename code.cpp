#include <cstdint>
#include <raylib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef int32_t i32;
typedef float f32;

constexpr i32 WIDTH{700};
constexpr i32 HEIGHT{500};

std::vector<Vector2> DimensionVector;

int main() {
    InitWindow(WIDTH, HEIGHT, "Perlin Noise");
    SetTargetFPS(60);

    for (i32 i = 0; i < 50; ++i) {
        f32 rand_x = std::rand() % WIDTH; 
        DimensionVector.push_back(Vector2{rand_x, HEIGHT / 2.0f});
    }

    while (!WindowShouldClose()) {
    
    BeginDrawing();
    ClearBackground(BLACK);

    for (i32 i = 0; i < DimensionVector.size(); ++i) {
        DrawCircle(DimensionVector[i].x, DimensionVector[i].y, 8.0f, WHITE); 
    }
    EndDrawing();
}

CloseWindow();

return 0;
}
