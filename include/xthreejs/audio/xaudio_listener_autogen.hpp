#ifndef XTHREE_AUDIO_LISTENER_HPP
#define XTHREE_AUDIO_LISTENER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // audio_listener declaration
    //

    template<class D>
    class xaudio_listener : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xaudio_listener();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using audio_listener = xw::xmaterialize<xaudio_listener>;

    using audio_listener_generator = xw::xgenerator<xaudio_listener>;

    //
    // audio_listener implementation
    //

    template <class D>
    inline void xaudio_listener<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xaudio_listener<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xaudio_listener<D>::xaudio_listener()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xaudio_listener<D>::set_defaults()
    {
        this->_model_name() = "AudioListenerModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xaudio_listener));
//}
#endif