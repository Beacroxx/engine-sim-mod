# engine-sim-mod

**->Keybinds<-** <br />
U -> Toggle Supercharger <br />
T -> Switch Transmission (Automatic / Manual) <br />
J -> Switch Transmission mode ( Comfort / Sport ) <br />

**->Defaults<-** <br />
Supercharger -> Off <br />
Transmission -> Manual <br />
Mode -> Comfort <br />

# How to install? <br />
Download this Repository and run the `engine-sim-app.exe` in the `bin` folder.

# How to Modify values?  <br />
Inside your engines `.mr` file, you can add <br />
```
max_pressure: [double], // Maximum Pressure in Bars
pulley_ratio: [double], // Supercharger pulley ratio. Bigger numbers increase Supercharger RPM, Lower numbers decrease Supercharger RPM.
```
into the engine node. <br />

**->Example<-** <br />
```
...
public node M52B28 {
    alias output __out: engine;

    engine engine(
        name: "BMW M52B28",
        starter_torque: 150 * units.lb_ft,
        starter_speed: 500 * units.rpm,
        redline: 7000 * units.rpm,
        max_pressure: 3.0,
        pulley_ratio: 1.0
    )
...
```

**->Information<-** <br />
Due to most Engines getting stuck at high rpm from the Supercharger, the Wastegate will only close if throttle is applied.
