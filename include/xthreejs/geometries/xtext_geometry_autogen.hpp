#ifndef XTHREE_TEXT_GEOMETRY_HPP
#define XTHREE_TEXT_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"

namespace xthree
{
    //
    // text_geometry declaration
    //

    template<class D>
    class xtext_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xtext_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using text_geometry = xw::xmaterialize<xtext_geometry>;

    using text_geometry_generator = xw::xgenerator<xtext_geometry>;

    //
    // text_geometry implementation
    //

    template <class D>
    inline void xtext_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xtext_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xtext_geometry<D>::xtext_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtext_geometry<D>::set_defaults()
    {
        this->_model_name() = "TextGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xtext_geometry));
//}
#endif