using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LifeComponent : MonoBehaviour
{
    [SerializeField] int initLife = 10;
    int currentLife = 0;
    public Action<Transform> onDead = null;
    public Action onDamage = null;

    private void Start()
    {
        currentLife = initLife;
    }

    public void Damage(int _damage)
    {
        currentLife -= _damage;
        if (currentLife <= 0)
        {
            onDead?.Invoke(transform);
            Destroy(gameObject);
            return;
        }
        onDamage?.Invoke(); 
    }
}