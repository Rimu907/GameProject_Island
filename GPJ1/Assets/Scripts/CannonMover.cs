using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CannonMover : MonoBehaviour
{
    public float speed1 = 15.0f;
    // Start is called before the first frame update
    void Start()
    {
        Rigidbody r1 = GetComponent<Rigidbody>();
        r1.velocity = transform.forward * speed1;
    }

    // Update is called once per frame
    void Update()
    {

    }
}