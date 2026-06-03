# Scripting the World
Imagine you're designing a 2D game engine where characters roam, enemies patrol, and power ups trigger hidden effects. At the heart of your engine is the **GameObject**: a class that stores everything a game entity needs to survive: its name, health, position, and animation state.

But there's a catch. To keep your code clean and well-structured, all this internal data is private. That's great for encapsulation, but what happens if other parts of your game engine need direct access to this data?

For example, a scripting engine might need to teleport a character across the map. A cutscene tool might want to trigger animations directly. Meanwhile, a debugging system may need to compare game objects or export their data to a file.

Instead of exposing everything publicly (which breaks your class design), you'll use friend functions and friend classes. These allow you to grant access to internal members, but only to specific, trusted collaborators.

In this project, you'll build a small but powerful simulation of a real-world game engine. You'll:

- Create a `GameObject` class with essential properties and behaviors.
- Write a `ScriptEngine` class that modifies game objects as a trusted friend.
- Add a friend function to compare objects or convert them into strings.
- Use operator overloading to improve readability and mimic real game engine behavior.

Let's bring your GameCore engine to life, one object at a time.