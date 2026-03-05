// 02-media-lsp-isp.cpp
// Messy starter: Fat interface + LSP surprises (violates ISP + LSP)

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class IPlayable {

    public:
    virtual void play(string source, bool isLive)  = 0;
    virtual void pause() = 0;
};

class AudioPlay : public IPlayable{ 

    public : 
    void play(string source, bool isLive) override {
        cout << "Playing audio from " << source << endl;
    }

    void pause() override{
        cout << "Pausing the audio" << endl;
    }
};

class CameraPlay : public IPlayable{

    public :
    void play(string source, bool isLive) override {

        if(!isLive){
            cout << "[WARN] playing without live stream started." << source << endl;

        }

        else cout << "Playing camera stream from " << source << endl;
    }

    void pause() override{
        cout << "Pausing the camera" << endl;
    }
};

class AudioDownloader {

    public :
    void download(string url){
        cout << "Audio is downloade from " << url << endl;
    }
};

class CameraRecorder{

    public : 
    void record(string dest ){
        cout << "Recording is saved to" << dest << endl;
    }
};

class CameraLiveStreamer {

    public :
    void stream(string liveUrl){
        cout << "Camera stream is being showed live to " << liveUrl << endl;
    }
};

// class Player {
// public:
//     virtual ~Player() = default;
//     virtual void play() = 0;
//     virtual void pause() = 0;
//     // virtual void record(const string& destination) = 0;  // many can't
//     // virtual void streamLive(const string& url) = 0;       // many can't
//     // virtual void download(const string& sourceUrl) = 0;   // many can't
// };


class AudioPlayer  {

    bool isPlaying;
    string source;
    string downloadUrl;
    IPlayable & playable;
    AudioDownloader downloader;


public:

    AudioPlayer(string src, string url, IPlayable & p) isPlaying(false) , source(src), downloadUrl(url), playable(p) {};
    

    void play() { 
        isPlaying = true;
        playable.play(source, false);

    }
    
    void pause() { 
        playable.pause();
        isPlaying = false; 
    }
    
    void download(){
        downloader.download(downloadUrl);
    }
    bool isPlaying() const { 
        return isPlaying; 
    }
};

class CameraStreamPlayer : {

    bool hasLiveStarted;
    string source;
    string liveUrl;
    bool isPlaying;
    IPlayable & playable;
    CameraRecorder camRecorder;
    CameraLiveStreamer camLiveStreamer;
public:

    CameraLiveStreamer(string src, string url, IPlayable & p){
        source = src;
        liveUrl = url;
        isPlaying = false;
        playable = p; 
        hasLiveStarted = false;
    }

    void play() override {
        // Surprise: needs streamLive first for “real” play
        playable.play(source, hasLiveStarted);
        isPlaying = true;
    }

    void pause() override { 
        playable.pause();
        isPlaying = true; 
    }

    void record() override { 

    }
    void streamLive() override { 
        hasLiveStarted = true;
        camLiveStreamer.stream(liveUrl);
        
    }
    bool isPlaying() const { return playing; }
    bool isLive() const { return hasLiveStarted; }
};

int main() {
//     AudioPlayer ap;
//     ap.play("song.mp3");
//     cout << "Audio playing: " << boolalpha << ap.isPlaying() << "\n";
//     ap.pause();

//     CameraStreamPlayer cam;
//     cam.play("rtsp://camera");       // warning surprise
//     cam.streamLive("rtsp://camera"); // required order
//     cam.play("rtsp://camera");
//     try { cam.download("http://file"); } catch (const exception& e) {
//         cout << "[EXC] " << e.what() << "\n";
//     }
//     return 0;
// }