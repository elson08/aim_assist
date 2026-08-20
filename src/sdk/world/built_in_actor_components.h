#pragma once

struct AABBShapeComponent;
struct ActorWalkAnimationComponent;
struct StateVectorComponent;
struct ActorRotationComponent;

struct BuiltInActorComponents {
	gsl::not_null<StateVectorComponent*> mStateVecComponent;
	gsl::not_null<AABBShapeComponent*> mShapeComponent;
	gsl::not_null<ActorRotationComponent*> mRotationComponent;
	gsl::not_null<ActorWalkAnimationComponent*> mActorWalkAnimationComponent;
};
