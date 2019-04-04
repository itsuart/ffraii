#include "AVFrameR.h"

namespace ffraii {
    const AVFrameR::WrappedType AVFrameR::s_invalidValue = nullptr;

    AVFrameR::AVFrameR()
    : m_resource(s_invalidValue)
    {}

    AVFrameR::AVFrameR(WrappedType resource)
    : m_resource(resource)
    {}

    AVFrameR::~AVFrameR(){
        release();
    }

    void AVFrameR::release(){
        if (m_resource != s_invalidValue){
            av_frame_free(&m_resource);
            m_resource = s_invalidValue;
        }
    }

    AVFrameR::AVFrameR(AVFrameR&& other)
    : m_resource(other.m_resource)
    {
        other.m_resource = s_invalidValue;
    }

    AVFrameR& AVFrameR::operator=(AVFrameR&& other){
        if (&other != this){
            release();
            m_resource = other.m_resource;
            other.m_resource = s_invalidValue;
        }

        return *this;
    }

    // returns true iff wrapped resource is valid
    AVFrameR::operator bool() const {
        return ok();
    }

    // returns true iff wrapped resource is valid
    bool AVFrameR::ok() const{
        return m_resource != s_invalidValue;
    }

    AVFrameR::operator WrappedType() const{
        return m_resource;
    }

    AVFrameR::WrappedType AVFrameR::unwrap() const {
        return m_resource;
    }

    AVFrameR::WrappedType* AVFrameR::p_value(){
        return &m_resource;
    }

    const AVFrameR::WrappedType* AVFrameR::p_value() const{
        return &m_resource;
    }
}
