using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EnemyHp : MonoBehaviour
{

    private int MaxHP = 100;
    public Slider slider;
    public int CurrentHP;
    public GameObject bloodEffect;
    public GameObject Potion;
    public GameObject crystal;
    public GameObject ShieldPotion;


    // Start is called before the first frame update

    private void Start()
    {
        CurrentHP = MaxHP;
    }


    public void TakeDamage(int damage)
    {
        Instantiate(bloodEffect, transform.position, Quaternion.identity);
        CurrentHP -= damage;
        ShowHPSlider();
        if (CurrentHP <= 0)
        {
            CurrentHP = 0;
            Sound.Playmonster();
            DestroyObject(gameObject);
            int Rnd = Random.Range(0, 3);
            switch (Rnd)
            {
            case 1: 
                 Instantiate(Potion, transform.position, Quaternion.identity);
                    break;
            case 0: 
                 Instantiate(crystal, transform.position, Quaternion.identity);
                    break;
            case 2:
                 Instantiate(ShieldPotion, transform.position, Quaternion.identity);
                    break;

            }
           
            
            //CurrentHP = 100;
        }
    }


    public void ShowHPSlider()
    {
        slider.value = (float)CurrentHP / (float)MaxHP;
    }

}
