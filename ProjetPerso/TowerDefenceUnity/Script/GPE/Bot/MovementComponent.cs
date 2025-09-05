using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovementComponent : MonoBehaviour
{
    [SerializeField] float speed = 1;
    bool stopMove = false;

    void Start()
    {
    }

    void LateUpdate()
    {
        if (stopMove)
            return;

        Move();
    }

    void Move()
    {
        Vector3 _newPosition = Vector3.Lerp(transform.position, transform.position + transform.forward, Time.deltaTime * speed);
        transform.position = _newPosition;
    }

    public void StopMove()
    {
        stopMove = true;
    }
}
