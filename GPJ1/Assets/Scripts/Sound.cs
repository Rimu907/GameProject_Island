using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sound : MonoBehaviour
{
    public static AudioSource audioSrc;
    public static AudioClip Gun;
    public static AudioClip cannon;
    public static AudioClip monster;
    public static AudioClip boss;
    public static AudioClip wallbreak;
    public static AudioClip dooropen;
    public static AudioClip dooropen1;
    public static AudioClip Shield;
    public static AudioClip potion;
    public static AudioClip Gamestart;
    public static AudioClip Dog;
    public static AudioClip win;
    public static AudioClip lose;




    // Start is called before the first frame update
    void Start()
    {
        audioSrc = GetComponent<AudioSource>();
        Gun = Resources.Load<AudioClip>("gun");
        monster = Resources.Load<AudioClip>("monsters");
        boss = Resources.Load<AudioClip>("boss");
        cannon = Resources.Load<AudioClip>("cannon");
        wallbreak = Resources.Load<AudioClip>("wallbreak");
        dooropen = Resources.Load<AudioClip>("door");
        dooropen1 = Resources.Load<AudioClip>("bigdoor");
        Shield = Resources.Load<AudioClip>("shield");
        potion = Resources.Load<AudioClip>("drink");
        Gamestart = Resources.Load<AudioClip>("bgm");
        Dog = Resources.Load<AudioClip>("Dog");
        win = Resources.Load<AudioClip>("SUCCESS");
        lose = Resources.Load<AudioClip>("lose");
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public static void Playgun()
    {
        audioSrc.PlayOneShot(Gun);
    }
    public static void Playmonster()
    {
        audioSrc.PlayOneShot(monster);
    }
    public static void Playboss()
    {
        audioSrc.PlayOneShot(boss);
    }
    public static void Playcannon()
    {
        audioSrc.PlayOneShot(cannon);
    }
    public static void Playwallbreak()
    {
        audioSrc.PlayOneShot(wallbreak);
    }
    public static void Playdoor()
    {
        audioSrc.PlayOneShot(dooropen);
    }
    public static void Playdoor1()
    {
        audioSrc.PlayOneShot(dooropen1);
    }
    public static void Playshield()
    {
        audioSrc.PlayOneShot(Shield);
    }
    public static void Playpotion()
    {
        audioSrc.PlayOneShot(potion);
    }
    public static void Playstart1()
    {
        audioSrc.PlayOneShot(Gamestart);
    }
    public static void PlayDog()
    {
        audioSrc.PlayOneShot(Dog);
    }
    public static void Playwin()
    {
        audioSrc.PlayOneShot(win);
    }
    public static void Playlose()
    {
        audioSrc.PlayOneShot(lose);
    }
}
