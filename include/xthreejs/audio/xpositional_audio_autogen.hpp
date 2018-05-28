#ifndef XTHREE_POSITIONAL_AUDIO_HPP
#define XTHREE_POSITIONAL_AUDIO_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // positional_audio declaration
    //

    template<class D>
    class xpositional_audio : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xpositional_audio();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using positional_audio = xw::xmaterialize<xpositional_audio>;

    using positional_audio_generator = xw::xgenerator<xpositional_audio>;

    //
    // positional_audio implementation
    //


    template <class D>
    inline void xpositional_audio<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xpositional_audio<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xpositional_audio<D>::xpositional_audio()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpositional_audio<D>::set_defaults()
    {
        this->_model_name() = "PositionalAudioModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xpositional_audio>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xpositional_audio>;
        extern template xw::xmaterialize<xthree::xpositional_audio>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xpositional_audio>>;
        extern template class xw::xgenerator<xthree::xpositional_audio>;
        extern template xw::xgenerator<xthree::xpositional_audio>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xpositional_audio>>;
    #endif
#endif

#endif