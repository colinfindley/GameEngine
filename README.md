# C++ Video Game Engine

Welcome to the C++ Video Game Engine! This engine is designed to provide a robust framework for developing video games, with a focus on performance and flexibility. It includes libraries for handling animations, math, complex tree data structures (PCS Tree), and more. The engine is optimized for SIMD and includes comprehensive managers for meshes, cameras, and textures.

## Features

- **Time Library**: Handles animations and ensures smooth frame transitions.
- **Engine Core**: The heart of the engine, managing initialization, game loops, and system resources.
- **Manager Library**: Manages various game components such as meshes, cameras, and textures.
- **Math Library**: Provides mathematical functions and structures optimized for SIMD.
- **PCS Tree Library**: A complex tree data structure for managing hierarchical relationships in games.

## Libraries and Components

### Time Library
The Time Library ensures smooth animations and frame transitions. It manages the game's internal clock, allowing for consistent time-based events.

### Engine Core
The Engine Core initializes the game, manages the game loop, and handles system resources. It is designed for high performance and flexibility, making it easy to extend and customize.

### Manager Library
The Manager Library includes several managers for handling different aspects of the game:

- **Mesh Manager**: Manages 3D models and mesh data.
- **Camera Manager**: Controls camera perspectives and movements.
- **Texture Manager**: Handles loading, binding, and managing textures.

### Math Library
The Math Library provides a variety of mathematical functions and structures, optimized for SIMD to ensure high performance. It includes vector, matrix, and quaternion operations essential for 3D game development.

### PCS Tree Library
The PCS Tree Library implements a complex tree data structure used for managing hierarchical relationships. This is useful for scene graphs, skeletal hierarchies, and other hierarchical data.

## SIMD Optimization
The engine is aligned and optimized for SIMD (Single Instruction, Multiple Data), ensuring efficient parallel processing and improved performance on supported hardware.
