using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BossHp : MonoBehaviour
{
    public int MaxHP = 200;
    public Slider slider;
    public int CurrentHP;
    public GameObject bloodEffect;
    public GameObject Potion;
    public GameObject crystal;
    public GameObject ShieldPotion;
    public GameObject CannonTrigger;
    public Transform bleedTransform;

    // Start is called before the first frame update
    private void Start()
    {
        CurrentHP = MaxHP;
    }

    // Update is called once per frame

    public void TakeDamage(int damage)
    {
        Instantiate(bloodEffect, bleedTransform.position, Quaternion.identity);
        CurrentHP -= damage;
        ShowHPSlider();
        if (CurrentHP <= 0)
        {
            CurrentHP = 0;
            Sound.Playboss();
            DestroyObject(gameObject);
      

            Instantiate(Potion, transform.position, Quaternion.identity);
            Instantiate(Potion, transform.position, Quaternion.identity);
            Instantiate(Potion, transform.position, Quaternion.identity);


            Instantiate(ShieldPotion, transform.position, Quaternion.identity);
            Instantiate(ShieldPotion, transform.position, Quaternion.identity);
            Instantiate(ShieldPotion, transform.position, Quaternion.identity);

            Instantiate(CannonTrigger, transform.position, Quaternion.identity);
            Instantiate(CannonTrigger, transform.position, Quaternion.identity);
            




        }
    }

    public void ShowHPSlider()
    {
        slider.value = (float)CurrentHP / (float)MaxHP;
    }

}

