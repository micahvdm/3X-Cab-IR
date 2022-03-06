# ToobAmp LV2 Guitar Amp Plugins

v0.0.1-Alpha.1

ToobAmp LV2 plugins are a set of high-quality guitar effect plugins for Raspberry Pi. They are specifically designed for use with the [PiPedal](https://github.com/rerdavies/pipedal) project, but work perfectly well with any LV2 Plugin host.

*   **TooB Input Stage**

    For initial conditioning of guitar input signals. Trim level, noise-gating, and an EQ section that 
    provides low-pass, hi-pass and bright-boost filtering.

    &nbsp;

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](docs/img/InputStage-ss.png)

    &nbsp;

*   **TooB Tone Stack**

    Guitar amplifier tone stack. Select a Fender Bassman, Marshal JCM800, or Baxandall tone stack.

    &nbsp;

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](docs/img/ToneStack-ss.png)

    &nbsp;    

*   **Toob ML Amplifier**

    Artificial-Intelligence/Machine-Learning-based emulation of a number of different guitar amps and overdrive/distortion
    pedals. 

    &nbsp;

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](docs/img/MlAmplifier.png)

    &nbsp;

*   **TooB Power Stage**

    Guitar amplifier power stage emulation. Three super-sampled gain stages with flexible control over
    distortion/overdrive characteristics allow you to generate anything from warm sparkling clean tones
    to blistering full-on overdrive. Generally used in conjunction with the TooB Tone Stack and Toob CamSim 
    plugins.

    &nbsp;

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](docs/img/Power-ss.png)

    &nbsp;

*   **TooB Cab Simulator**

    Rather than relying on expensive convolution effects, Toob CabSim provides an EQ section designed to 
    allow easy emulation of guitar cabinet/microphone combinations. 

    &nbsp;

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](docs/img/CabSim-ss.png)

    &nbsp;

*   **TooB FreeVerb**

    A particularly well-balanced Reverb plugin, based on the famous FreeVerb algorithm.

    &nbsp;

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](docs/img/FreeVerb-ss.png)

    &nbsp;

*   **TooB Tuner**

    An stable, accurate guitar tuner. (Currently only useful with PiPedal).

    &nbsp;

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](docs/img/Tuner-ss.png)

    &nbsp;

*   **TooB Spectrum Analyzer**

    Live-signal spectrum analyzer. (Currently only useful with PiPedal).

    &nbsp;

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![](docs/img/SpectrumAnalyzer.png)

    &nbsp;

## Building ToobAmp

Prerequisites:

     apt install lv2-dev
	
If you have not installed Visual Studio Code, you will need to install CMake:

    apt install cmake

ToobAmp was built using Visual Studio Code, with CMake build files.

If you are using Visual Studio code, install the Microsoft CMake extension, and load the project directory. Visual Studio Code
will automatically detect and configure the project. Build and configuration tools for the CMake project can be accessed on the Visual Studio Code status bar.

If you are not usings Visual Studio Code, the following shell scripts, found in the root of the project, can be used to configure, build and instal the project:

    ./config     #configure the CMake project
   
    ./bld   # build the project.
    
After a full build, run the following command to install ToobAmp:

    sudo ./install
	
To rebuild the debian package, run

    sudo ./makePackage


