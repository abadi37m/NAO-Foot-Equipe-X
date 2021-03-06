// Generated for ALAudioPlayer version 1.14

#ifndef ALAUDIOPLAYERPROXY_H_
#define ALAUDIOPLAYERPROXY_H_
#include <alproxies/alaudioplayerproxyposthandler.h>

#include <alproxies/api.h>



namespace AL
{
class ALBroker;
class ALProxy;

class ALAudioPlayerProxyImpl;

/// <summary>This module allows to play wav and mp3 files on NAO</summary>
/// \ingroup ALProxies
class ALPROXIES_API ALAudioPlayerProxy
{
  private:
    boost::shared_ptr<ALAudioPlayerProxyImpl> fImpl;
    void xInit();

  public:
    /// <summary>
    /// Default Constructor. If there is a broker in your process, which is always the case
    /// if you are in a module, then this will be found and used.
    /// </summary>
    ALAudioPlayerProxy();

    /// <summary>
    /// Explicit Broker Constructor. If you have a smart pointer to a broker that you want
    /// to specify, then you can use this constructor. In most cases, the default constructor
    /// will do the work for you without passing a broker explicitly.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALAudioPlayerProxy(boost::shared_ptr<ALBroker> broker);

    /// <summary>
    /// Explicit Proxy Constructor. Create a specialised proxy from a generic proxy.
    /// </summary>
    /// <param name="broker">A smart pointer to your broker</param>
    ALAudioPlayerProxy(boost::shared_ptr<ALProxy> proxy);


    /// <summary>
    /// Remote Constructor. This constructor allows you to connect to a remote module by
    /// explicit IP address and port. This is useful if you are not within a process that
    /// has a broker, or want to connect to a remote instance of NAOqi such as another
    /// robot.
    /// </summary>
    /// <param name="ip">The IP address of the remote module you want to connect to</param>
    /// <param name="port">The port of the remote module, typically 9559</param>
    ALAudioPlayerProxy(std::string ip, int port=9559);

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALAudioPlayerProxyPostHandler post;

    // --- access to ALProxy ----

    /// <summary>
    /// Gets the underlying generic proxy
    /// </summary>
    boost::shared_ptr<ALProxy> getGenericProxy();

    // ------------------------------

    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit();

    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName();

    /// <summary>
    /// Returns the position in the file which is currently played
    /// </summary>
    /// <param name="playId"> Id of the process which is playing the file </param>
    /// <returns> Position in the file in seconds </returns>
    float getCurrentPosition(const int& playId);

    /// <summary>
    /// Returns the length of the file played
    /// </summary>
    /// <param name="playId"> Id of the process which is playing the file </param>
    /// <returns> Length of the file in seconds </returns>
    float getFileLength(const int& playId);

    /// <summary>
    /// returns an array containing the Ids of the currently loaded files
    /// </summary>
    /// <returns> Array containing the Ids of the files which has been loaded </returns>
    std::vector<std::string> getLoadedFilesIds();

    /// <summary>
    /// returns an array containing the names of the currently loaded files
    /// </summary>
    /// <returns> Array containing the names of the files which has been loaded </returns>
    std::vector<std::string> getLoadedFilesNames();

    /// <summary>
    /// Returns the master volume of the player
    /// </summary>
    /// <returns> Volume of the master - range 0.0 to 1.0. </returns>
    float getMasterVolume();

    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName);

    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList();

    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp();

    /// <summary>
    /// Gets the method usage string. This summarises how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name);

    /// <summary>
    /// Returns the volume of the player
    /// </summary>
    /// <param name="playId"> Id of the process which is playing the file </param>
    /// <returns> Volume of the player - range 0.0 to 1.0. </returns>
    float getVolume(const int& playId);

    /// <summary>
    /// Goes to a given position in a file which is playing.
    /// </summary>
    /// <param name="playId"> Id of the process which is playing the file </param>
    /// <param name="position"> Position in the file (in second) </param>
    void goTo(const int& playId, const float& position);

    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id);

    /// <summary>
    /// Loads a file for ulterior playback
    /// </summary>
    /// <param name="fileName"> Path of the sound file (either mp3 or wav) </param>
    /// <returns> Id of the file which has been loaded. This file can then be played with the play function </returns>
    int loadFile(const std::string& fileName);

    /// <summary>
    /// Pause a play back
    /// </summary>
    /// <param name="id"> Id of the process that is playing the file you want to put in pause </param>
    void pause(const int& id);

    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping();

    /// <summary>
    /// Starts the playback of a file preloaded with the loadFile function.
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    void play(const int& id);

    /// <summary>
    /// Starts the playback of a file preloaded with the loadFile function, with specific volume and audio balance
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
    void play(const int& id, const float& volume, const float& pan);

    /// <summary>
    /// Plays a wav or mp3 file
    /// </summary>
    /// <param name="fileName"> Path of the sound file </param>
    void playFile(const std::string& fileName);

    /// <summary>
    /// Plays a wav or mp3 file, with specific volume and audio balance
    /// </summary>
    /// <param name="fileName"> Path of the sound file </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right / 0.0 : centered) </param>
    void playFile(const std::string& fileName, const float& volume, const float& pan);

    /// <summary>
    /// Plays a wav or mp3 file from a given position in the file.
    /// </summary>
    /// <param name="fileName"> Name of the sound file </param>
    /// <param name="position"> Position in second where the playing has to begin </param>
    void playFileFromPosition(const std::string& fileName, const float& position);

    /// <summary>
    /// Plays a wav or mp3 file from a given position in the file, with specific volume and audio balance
    /// </summary>
    /// <param name="fileName"> Name of the sound file </param>
    /// <param name="position"> Position in second where the playing has to begin </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
    void playFileFromPosition(const std::string& fileName, const float& position, const float& volume, const float& pan);

    /// <summary>
    /// Plays a wav or mp3 file in loop
    /// </summary>
    /// <param name="fileName"> Path of the sound file </param>
    void playFileInLoop(const std::string& fileName);

    /// <summary>
    /// Plays a wav or mp3 file in loop, with specific volume and audio balance
    /// </summary>
    /// <param name="fileName"> Path of the sound file </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
    void playFileInLoop(const std::string& fileName, const float& volume, const float& pan);

    /// <summary>
    /// Starts the playback in loop of a file preloaded with the loadFile function
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    void playInLoop(const int& id);

    /// <summary>
    /// Plays a wav or mp3 file in loop, with specific volume and audio balance
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    /// <param name="volume"> volume of the sound file (must be between 0.0 and 1.0) </param>
    /// <param name="pan"> audio balance of the sound file (-1.0 : left / 1.0 : right) </param>
    void playInLoop(const int& id, const float& volume, const float& pan);

    /// <summary>
    /// Play a sine wave which specified caracteristics.
    /// </summary>
    /// <param name="frequence"> Frequence in Hertz </param>
    /// <param name="gain"> Volume Gain between 0 and 100 </param>
    /// <param name="pan"> Stereo Pan set to either {-1,0,+1} </param>
    /// <param name="duration"> Duration of the sine wave in seconds </param>
    void playSine(const int& frequence, const int& gain, const int& pan, const float& duration);

    /// <summary>
    /// Starts the playback of a wab audio stream
    /// </summary>
    /// <param name="streamName"> Path of the web audio stream </param>
    /// <param name="arg2"> arg </param>
    /// <param name="arg3"> arg </param>
    void playWebStream(const std::string& streamName, const float& arg2, const float& arg3);

    /// <summary>
    /// Sets the master volume of the player
    /// </summary>
    /// <param name="volume"> Volume - range 0.0 to 1.0 </param>
    void setMasterVolume(const float& volume);

    /// <summary>
    /// sets the audio panorama : -1 for left speaker / 1 for right speaker
    /// </summary>
    /// <param name="arg1"> arg </param>
    void setPanorama(const float& arg1);

    /// <summary>
    /// Sets the volume of the player
    /// </summary>
    /// <param name="id"> Id of the process that is playing the file you want to put louder or less loud </param>
    /// <param name="volume"> Volume - range 0.0 to 1.0 </param>
    void setVolume(const int& id, const float& volume);

    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id);

    /// <summary>
    /// Stops all the files that are currently playing.
    /// </summary>
    void stopAll();

    /// <summary>
    /// unloads all the files already loaded.
    /// </summary>
    void unloadAllFiles();

    /// <summary>
    /// unloads a file previously loaded with the loadFile function
    /// </summary>
    /// <param name="id"> Id returned by the loadFile function </param>
    void unloadFile(const int& id);

    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version();

    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod);

};

}
#endif // ALAUDIOPLAYERPROXY_H_

