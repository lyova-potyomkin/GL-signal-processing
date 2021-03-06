# Digital signal processing

This is a digital signal processing app for GlobalLogic C++ practice.

It is not meant to be very useful and still is a work in progress.

## Installation

**Dependencies:**

- `libsndfile` for writing `.wav` files
- `libSDL2` for playing `.wav` files
- `python3` with `matplotlib` and `numpy` for signal visualisation

To install, clone the repo and then simply write `make`.

## Usage

The program is interactive, issue `help` command for details.

**Features:**

- Generate a digital signal within a chosen timespan
- Mix signals with different parameters
- Signals may differ by amplitude, frequency, phase, and type (Sine, Triangle, Rectangle)
- Save signals to `.csv` or `.wav` files
- Load signals from `.csv` files
- Play signals
- Graph signals
