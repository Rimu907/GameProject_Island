using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WoodShield : MonoBehaviour
{
    private int acc = 0;
    public int ShieldValue;
    public GameObject shieldeff;
    public Transform shieldeffpos;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (acc == ShieldValue)
        {
            Instantiate(shieldeff, shieldeffpos.position, shieldeffpos.rotation);
            DestroyObject(gameObject);
        }
    }
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "EnemyBullet")
        {
            Sound.Playshield();
            acc += 1;
        }
    }
}
