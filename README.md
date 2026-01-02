# Ohm.Engine
A minimal engine, focused on software rendering for the game Ohm.

It is Windows only, since it directly talks to the WinAPI, so Mac or Linux is not supported.

The idea of the engine is to target folks with lower-spec hardware, and I mean very-low spec.
Or enable developers with only CPUs to make 3D graphical applications. The engine is not meant to be
archaic in any way. I wanted to take on a more fun-to-type and open API. It's yours to tinker with.

As of right now it's not optimized with SIMD, it uses purely scalar math.
If the engine turns out to actually be pretty fast with scalar math (which I highly doubt) then I will not add SIMD math.
Though SIMD will be used in some parts like rasterization, or clearing the screen.

Another thing is if you are going to clone this repo, I do not guarantee portability, it's not my main focus as of right now.
If it works on your machine good, if it doesn't, I'll hopefully get to it later. If it doesn't work on your machine I would appreciate an
issue being reported.
