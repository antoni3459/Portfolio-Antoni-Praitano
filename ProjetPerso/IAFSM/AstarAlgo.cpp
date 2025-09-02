// Fill out your copyright notice in the Description page of Project Settings.


#include "AstarAlgo.h"
#include "Algo/Reverse.h"

void UAstarAlgo::ComputePath(UNodeNav* _start, UNodeNav* _end)
{
    _start->GetGrid()->ResetCost();
    if (!correctPath.IsEmpty())
        correctPath.Empty();
    TArray<UNodeNav*> _openList, _closedList;
    _start->SetG(0);
    _start->SetH(0);
    _openList.Add(_start);
    while (_openList.Num() > 0)
    {
        UNodeNav* _current = _openList[0];
        _openList.Remove(_current);
        _closedList.Add(_current);
        if (_current == _end)
        {
            correctPath = GetFinalPath(_start, _end);
            return;
        }
        for (int i = 0; i < _current->GetSuccessors().Num(); i++)
        {
            UNodeNav* _next = _current->GetGrid()->GetNodes()[_current->GetSuccessors()[i]];

            if (_closedList.Contains(_next) || _next->GetIsClose())
                continue;
            float _hCost = FVector::Distance(_current->GetPosition(), _end->GetPosition());
            float _gCost = _current->GetG() + _hCost;
            if (_gCost < _next->GetG() || !_openList.Contains(_next))
            {
                _next->SetG(_gCost);
                _next->SetH(_hCost);
                _next->SetParent(_current);
                _openList.Add(_next);
            }
        }
    }
}

TArray<UNodeNav*> UAstarAlgo::GetFinalPath(UNodeNav* _start, UNodeNav* _end)
{
    TArray<UNodeNav*> _path;
    UNodeNav* _current = _end;
    _path.Add(_end);
    while (_current != _start)
    {
        _path.Add(_current->GetParent());
        _current = _current->GetParent();
    }
    Algo::Reverse(_path);
    return _path;
}

void UAstarAlgo::DrawPath()
{
    for (int i = 0; i < correctPath.Num(); i++)
    {
        DrawDebugLine(GetWorld(), correctPath[i]->GetPosition(), correctPath[i + 1]->GetPosition(),FColor::Magenta);
    }
}
