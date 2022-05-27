#ifndef CAMERA_H
#define CAMERA_H
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"

class Camera {
public:

	glm::mat4 getViewMatrix() const;
	virtual void rotate(float yaw, float pitch) {}; // in degrees
	virtual void setPosition(const glm::vec3& position) {};
	virtual void move(const glm::vec3& offsetPos) {};

	const glm::vec3& getLook() const;
	const glm::vec3& getRight() const;
	const glm::vec3& getUp() const;
	const glm::vec3& getPosition() const;

	float getFOV() const { return mFOV; }
	void setFOV(float fov) { mFOV = fov; }; // in degrees

protected:
	Camera();

	glm::vec3 mPosition;
	glm::vec3 mTargetPos;
	glm::vec3 mUp;
	glm::vec3 mLook;
	glm::vec3 mRight;
	const glm::vec3 WORLD_UP;

	// Euler angles (in radians)
	float mYaw;
	float mPitch;

	float mFOV; // degrees
};

class OrbitCamera : public Camera {
public:
	OrbitCamera();

	virtual void rotate(float yaw, float pitch); // in degress

	void setLookAt(const glm::vec3& target);
	void setRadius(float radius);

private:

	void updateCameraVectors();
	float mRadius;
};


class FPSCamera : public Camera {
public:
	FPSCamera(glm::vec3 position = glm::vec3(.0f, .0f, .0f), float yaw = glm::pi<float>(), float pitch = 0.0f); // (yaw) initial angle faces -Z

	virtual void rotate(float yaw, float pitch); // in degrees
	virtual void setPosition(const glm::vec3& position);
	virtual void move(const glm::vec3& offsetPos);

private:
	void updateCameraVectors();
};



#endif