using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Diagnostics;

public class AttackComponent : MonoBehaviour
{
    [SerializeField] int coolDown = 1;
    [SerializeField] int damage = 2;
    [SerializeField] LayerMask interactLayer;
    [SerializeField] MovementComponent movementComponent = null;

    Mob selfMob = null;
    Transform target = null;

    bool attackMode = false;

    public Action OnAttack = null;
    public Action OnStopAttack = null;

    private void Awake()
    {
    }

    void Start()
    {
        if(GetComponent<Mob>())
            selfMob = GetComponent<Mob>();
    }

    void Update()
    {
        if (target)
            return;
        bool _hit = Physics.Raycast(transform.position, transform.forward * 3, out RaycastHit _result, 5, interactLayer);
        if (_hit)
            EnterCollision(_result.collider);
    }
	private void OnDrawGizmos()
	{
		Gizmos.DrawLine(transform.position, transform.position + transform.forward * 3);
	}
	private void EnterCollision(Collider _collider)
    {
        GPE _gpe = _collider.GetComponent<GPE>();
		if (_gpe && _gpe.WithPlayer != selfMob.WithPlayer)
            AttackMode(_gpe);
    }

    private void AttackMode(GPE _target)
    {
        movementComponent.StopMove();

        attackMode = true;
        target = _target.transform;
        OnAttack?.Invoke();
        InvokeRepeating("Attack", coolDown, coolDown);
    }

    private void ExitCollision(Collider _collider)
    {
        attackMode = false;
    }

    void Attack()
    {
        if (!attackMode)
        {
            CancelInvoke("Attack");
            return;
        }
        target.GetComponent<LifeComponent>().Damage(damage);
    }
}
