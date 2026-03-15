# Week 1

Three items: my thoughts, main idea of the topic, knowledge gap.
I wanna be short thus my notes might sound weird. 🤪

## Day 0 - preparation
- It took more time than I expected.

## Day 1 - A Tour of C++ (page 1 - 5)
- I'm on the page 5, lol. It looks like I need more time or be more focused.
- The gap - we can skip arguments by omitting the names and use the one we need.

## Day 2 - A Tour of C++ (page 5 - 14)
- If a function may have to be evaluated at compile time, declare it _constexpr_.
- Prefer the {}-initializer syntax for declarations with a named type.
- Gap: {} is general for all types, I'm used to use it with containers.

## Day 3 - A Tour of C++ (page 15 - 18)
- It is so slowly :(
- A `struct` is simply a `class` with members _public_ by default.
- Gap: `new double[s]` is still used, I'm used to `std::vector<double> v(s)`

## Day 4 - A Tour of C++ (page 19 - 21)
- Better to use `class enums` over `plain enums` to minimize surprises;
- `union` is a struct where all members are allocated at the same address!
- Gap: `union` struct, if you need it, use `std::variant` (never used it)

## Day 5 - A Tour of C++ (no more page ranges)
- Re-factoring of study method/plan.
- Sum up basics of constructor, destructor, RAII, lifetime object
- Gap: destructors are called in reverse order

