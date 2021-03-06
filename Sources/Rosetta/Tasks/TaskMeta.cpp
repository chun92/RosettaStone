// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Tasks/TaskMeta.hpp>
#include <utility>

namespace RosettaStone
{
TaskMetaTrait::TaskMetaTrait(TaskID id) : m_id(id)
{
    // Do nothing
}

TaskMetaTrait::TaskMetaTrait(TaskID id, TaskStatus status)
    : m_id(id), m_status(status)
{
    // Do nothing
}

TaskMetaTrait::TaskMetaTrait(TaskID id, TaskStatus status, std::size_t userID)
    : m_id(id), m_status(status), m_userID(userID)
{
    // Do nothing
}

bool TaskMetaTrait::operator==(const TaskMetaTrait& trait) const
{
    return m_id == trait.m_id && m_status == trait.m_status &&
           m_userID == trait.m_userID;
}

TaskID TaskMetaTrait::GetID() const
{
    return m_id;
}

void TaskMetaTrait::SetID(TaskID id)
{
    m_id = id;
}

TaskStatus TaskMetaTrait::GetStatus() const
{
    return m_status;
}

void TaskMetaTrait::SetStatus(TaskStatus status)
{
    m_status = status;
}

std::size_t TaskMetaTrait::GetUserID() const
{
    return m_userID;
}

TaskMeta::TaskMeta(const TaskMetaTrait& trait) : TaskMetaTrait(trait)
{
    // Do nothing
}

TaskMeta::TaskMeta(const TaskMetaTrait& trait, std::any object)
    : TaskMetaTrait(trait), m_object(std::move(object))
{
    // Do nothing
}

TaskMeta::TaskMeta(TaskMeta&& meta) noexcept
    : TaskMetaTrait(meta), m_object(std::move(meta.m_object))
{
    // Do nothing
}

TaskMeta& TaskMeta::operator=(TaskMeta&& meta) noexcept
{
    TaskMetaTrait::operator=(meta);
    m_object = std::move(meta.m_object);
    return *this;
}

void TaskMeta::Reset()
{
    m_object.reset();
}

bool TaskMeta::HasObjects() const
{
    return m_object.has_value();
}
}  // namespace RosettaStone
