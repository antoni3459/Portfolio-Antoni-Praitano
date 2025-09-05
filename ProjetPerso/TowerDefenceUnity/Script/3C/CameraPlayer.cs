using System;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.InputSystem;


public class CameraPlayer : MonoBehaviour
{
    [SerializeField] float speed = 3;

    InputContexte contexte = null;
    InputAction movement = null;

	private void Awake()
	{
		contexte = new InputContexte();

     
	}

	void Start()
    {
        
    }

    void Update()
    {
		Move();

	}

	void Move()
	{
		float _move = movement.ReadValue<float>();
		Vector3 _newLocation = Vector3.Lerp(transform.position, transform.position + transform.right * _move, Time.deltaTime * speed);
		transform.position = _newLocation;
	}

	private void OnEnable()
	{
        movement = contexte.Input3C.Movement;
		movement.Enable();
	}

	private void OnDisable()
	{
		movement.Disable();
	}
}
