#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_

class SoundManager
{
public:
	static void playClickEffect();
	static void playIncomingWave();
	static void playNextWaveReady();
	
    static void playMageShot();
	
public:
	static void playWelcomeBackMusic();
	static void playJungleBattle();
	static void playDesertBattle();
	static void playGameTheme1();
public:
	//BOSS 100
	static void playEfreetiLaugh();
	static void playEfreetiClap();
	static void playEfreetiDeath();
private:
	static bool checkEffectState();
};

#endif
